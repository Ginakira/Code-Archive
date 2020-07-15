/************************************************************
    File Name : P1265-公路修建.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/07/15 18:17:44
************************************************************/

#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int n, xy[5005][2], vis[5005];
double dis[5005];

struct Node {
    int now;
    double val;
    bool operator<(const Node &b) const { return this->val > b.val; }
};

double distance(int a, int b) {
    long long x = xy[a][0] - xy[b][0];
    long long y = xy[a][1] - xy[b][1];
    return sqrt(x * x + y * y);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        dis[i] = 999999999999;
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", &xy[i][0], &xy[i][1]);
    }
    priority_queue<Node> que;
    que.push((Node){1, 0});
    dis[1] = 0;
    double ans = 0;
    int already = 0;
    while (!que.empty()) {
        Node temp = que.top();
        que.pop();
        if (vis[temp.now] == 1) {
            continue;
        }
        vis[temp.now] = 1;
        ans += temp.val;
        already++;
        if (already == n) {
            break;
        }
        for (int i = 1; i <= n; ++i) {
            if (i == temp.now) {
                continue;
            }
            double t = distance(temp.now, i);
            if (t < dis[i]) {
                dis[i] = t;
                que.push((Node){i, t});
            }
        }
    }

    printf("%.2f\n", ans);

    return 0;
}