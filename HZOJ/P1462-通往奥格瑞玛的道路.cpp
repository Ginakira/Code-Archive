/************************************************************
    File Name : P1462-通往奥格瑞玛的道路.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/07/01 20:39:34
************************************************************/
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
#define MAX_N 10000

struct Edge {
    int to, val, next;
};

struct Node {
    int now, val;
    bool operator<(const Node &b) const { return this->val > b.val; }
};

Edge edg[100005];

int n, m, b, edg_cnt, cost[MAX_N + 5], head[MAX_N + 5], ans[MAX_N + 5];

void make_edge(int a, int b, int c) {
    edg[edg_cnt].to = b;
    edg[edg_cnt].val = c;
    edg[edg_cnt].next = head[a];
    head[a] = edg_cnt++;
}

bool dijkstra(int mmax) {
    memset(ans, 0x3F, sizeof(ans));
    priority_queue<Node> que;
    que.push((Node){1, 0});
    ans[1] = 0;
    while (!que.empty()) {
        Node temp = que.top();
        que.pop();
        if (temp.val > ans[temp.now]) continue;
        for (int i = head[temp.now]; i != -1; i = edg[i].next) {
            int to = edg[i].to, val = edg[i].val;
            if (cost[to] <= mmax && ans[to] > temp.val + val) {
                ans[to] = temp.val + val;
                que.push((Node){to, ans[to]});
            }
        }
    }
    if (ans[n] >= b || ans[n] == 0x3f3f3f3f) {
        return false;
    } else {
        return true;
    }
}

int main() {
    memset(head, -1, sizeof(head));
    cin >> n >> m >> b;
    for (int i = 1; i <= n; ++i) {
        cin >> cost[i];
    }
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        make_edge(a, b, c);
        make_edge(b, a, c);
    }
    int l = 0, r = 1000000000;
    while (l != r) {  // 00000111111
        int mid = (l + r) >> 1;
        if (dijkstra(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    if (l == 1000000000) {
        cout << "AFK\n";
    } else {
        cout << l << endl;
    }
    return 0;
}