/************************************************************
    File Name : P3393-逃离僵尸岛.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/07/01 19:10:11
************************************************************/
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
typedef long long LL;
#define MAX_N 100000

struct Edge {
    int to, next;
};

struct Node {
    LL now, val;
    bool operator<(const Node &b) const { return this->val > b.val; }
};

struct Status {
    LL now, left;  // 现在在的点 还应该搜多远的距离
};

Edge edg[4 * MAX_N + 5];

LL n, m, k, s, p, q, head[MAX_N + 5], edg_cnt, ans[MAX_N + 5],
    zombie[MAX_N + 5];
char status[MAX_N + 5];  // Max-zombie 1-danger 0-normal

void make_edge(int a, int b) {
    edg[edg_cnt].to = b;
    edg[edg_cnt].next = head[a];
    head[a] = edg_cnt;
    edg_cnt++;
}

void init_status() {
    queue<Status> que;
    for (int i = 0; i < k; ++i) {
        que.push((Status){zombie[i], s});
        status[zombie[i]] = 0x3F;
    }
    while (!que.empty()) {
        Status temp = que.front();
        que.pop();
        if (temp.left == 0) continue;
        for (int i = head[temp.now]; i != -1; i = edg[i].next) {
            if (status[edg[i].to] == 0) {
                status[edg[i].to] = 1;
                que.push((Status){edg[i].to, temp.left - 1});
            }
        }
    }
}

LL dist(int x) {  // 求点权
    if (status[x] == 0) {
        return p;
    } else if (status[x] == 1) {
        return q;
    }
    return 0x3F3F3F3F3F3F3F3F;
}

void dijkstra() {
    priority_queue<Node> que;
    que.push((Node){1, 0});
    ans[1] = 0;
    while (!que.empty()) {
        Node temp = que.top();
        que.pop();
        if (temp.val > ans[temp.now]) continue;
        for (int i = head[temp.now]; i != -1; i = edg[i].next) {
            if (ans[edg[i].to] > ans[temp.now] + dist(edg[i].to)) {
                ans[edg[i].to] = ans[temp.now] + dist(edg[i].to);
                que.push((Node){edg[i].to, ans[edg[i].to]});
            }
        }
    }
}

int main() {
    memset(head, -1, sizeof(head));
    memset(ans, 0x3F, sizeof(ans));
    cin >> n >> m >> k >> s >> p >> q;
    for (int i = 0; i < k; ++i) {
        cin >> zombie[i];
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        make_edge(a, b);
        make_edge(b, a);
    }
    init_status();
    dijkstra();
    cout << ans[n] - dist(n) << endl;
    return 0;
}