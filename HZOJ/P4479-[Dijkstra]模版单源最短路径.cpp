/************************************************************
    File Name : P3371-[Dijkstra]模版单源最短路径（弱化版）.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/06/09 23:32:31
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 0x3f3f3f3f

struct Node {
    int now, dist;
    bool operator<(const Node &b) const { return this->dist > b.dist; }
};

int n, m, s, ans[1005];

int main() {
    cin >> n >> m >> s;
    int dis[n + 5][n + 5];
    memset(dis, 0x3f, sizeof(dis));
    memset(ans, 0x3f, sizeof(ans));
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        dis[a][b] = min(dis[a][b], c);
    }
    priority_queue<Node> que;
    que.push({s, 0});
    while (!que.empty()) {
        Node t = que.top();
        que.pop();
        if (ans[t.now] != INF) continue;
        ans[t.now] = t.dist;
        for (int i = 1; i <= n; ++i) {
            if (dis[t.now][i] != INF) {
                que.push({i, t.dist + dis[t.now][i]});
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        i == 1 || cout << " ";
        if (ans[i] != INF) {
            cout << ans[i];
        } else {
            cout << 0x7fffffff;
        }
    }
    cout << endl;
    return 0;
}