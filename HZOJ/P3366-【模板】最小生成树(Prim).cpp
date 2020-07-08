/************************************************************
    File Name : P3366-【模板】最小生成树(Prim).cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/07/08 18:49:06
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 200000

struct Edge {
    int to, val, next;
};

struct Node {
    int now, val;
    bool operator<(const Node &b) const { return this->val > b.val; }
};

Edge edge[2 * (MAX_N + 5)];
int n, m, edg_cnt, head[5005], ans, already, visit[5005], dis[5005];

void add_edg(int a, int b, int c) {}

int main() {
    memset(head, -1, sizeof(head));
    memset(dis, 0x3f, sizeof(dis));
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        add_edg(a, b, c);
        add_edg(b, a, c);
    }
    return 0;
}