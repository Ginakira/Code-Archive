/************************************************************
    File Name : #241-最近点对 2.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/06 19:28:16
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 100000
#define INF 0x3f3f3f3f

struct node {
    int x, y, z;
};

int n, px[MAX_N * 50 + 5], px_ind;
node p[(2 * MAX_N) + 5];

bool cmp(node a, node b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

bool cmp2(int a, int b) { return p[px[a]].y < p[px[b]].y; }

inline double dis(int p1, int p2) {
    return sqrt(pow(p[p1].x - p[p2].x, 2) + pow(p[p1].y - p[p2].y, 2));
}

double func(int l, int r) {
    if (l == r) return INF;
    if (l + 1 == r) {
        if (p[l].z != p[r].z) return dis(l, r);
        return INF;
    }
    int mid = (l + r) >> 1;
    double d = min(func(l, mid), func(mid + 1, r));
    int raw = px_ind;
    for (int i = mid; i >= l && p[mid].x - p[i].x < d; --i) {
        px[px_ind++] = i;
    }
    for (int j = mid + 1; j <= r && p[j].x - p[mid].x < d; ++j) {
        px[px_ind++] = j;
    }
    sort(px + raw, px + px_ind, cmp2);
    for (int i = raw; i < px_ind; ++i) {
        for (int j = i + 1; j < px_ind && p[j].y - p[i].y < d; ++j) {
            if (p[px[i]].z != p[px[j]].z) d = min(d, dis(px[i], px[j]));
        }
    }
    return d;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &p[i].x, &p[i].y);
        p[i].z = 1;
    }
    for (int i = 2 * n - 1; i >= n; --i) {
        scanf("%d%d", &p[i].x, &p[i].y);
        p[i].z = 2;
    }
    sort(p, p + 2 * n, cmp);
    double ans = func(0, 2 * n - 1);
    printf("%.3f\n", ans);
    return 0;
}