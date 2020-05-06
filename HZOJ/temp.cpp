/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/06 19:21:34
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
    int x, y;
};

bool cmp(node a, node b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

int n;
node p[MAX_N + 5];

inline double dis(int p1, int p2) {
    return sqrt(pow(p[p1].x - p[p2].x, 2) + pow(p[p1].y - p[p2].y, 2));
}

double func(int l, int r) {
    if (l == r) return INF;
    if (l + 1 == r) {
        return dis(l, r);
    }
    int mid = (l + r) >> 1;
    double d = min(func(l, mid), func(mid + 1, r));
    return d;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &p[i].x, &p[i].y);
    }
    sort(p, p + n, cmp);
    double ans = func(0, n - 1);
    printf("%lf\n", ans);
    return 0;
}