#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
#define MAXN 12500000

int ans;
int pre[MAXN];

struct Point{
    int x, y, id;
};

struct Road{
    int u, v;
    double w;
};

double dis(Point a, Point b) {
    return sqrt(1.0 * (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

void init(int n) {
    for (int i = 0; i < n * n / 2; ++i) {
        pre[i] = i;
    }
    return;
}

int find(int key) {
    if (pre[key] == key) return key;
    return pre[key] = find(pre[key]);
}

bool cmp(Road a, Road b) { return a.w < b.w; }

Point p[5050];
Road r[MAXN];
int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i].x >> p[i].y;
        p[i].id = i;
    }
    int r_cnt = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            r[r_cnt].u = p[i].id;
            r[r_cnt].v = p[j].id;
            r[r_cnt++].w = dis(p[i], p[j]);
        }
    }
    init(r_cnt);
    sort(r, r + r_cnt + 1, cmp);
    double cost = 0;
    for (int i = 1; i <= n * (n - 1) / 2; ++i) {
        int ra = find(r[i].u);
        int rb = find(r[i].v);
        if(ra != rb) {
            pre[ra] = rb;
            cost += r[i].w;
        }
    }
    printf("%.2f\n", cost);
    return 0;
}