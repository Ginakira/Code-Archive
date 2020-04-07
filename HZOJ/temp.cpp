/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/07 11:13:41
************************************************************/

#include <cstdio>
#include <iostream>
using namespace std;
#define MAX_N 100000
#define lc(ind) (tree[ind].lind)
#define rc(ind) (tree[ind].rind)
#define sum(ind) (tree[ind].sum)
#define tag(ind) (tree[ind].tag)
#define cnt(ind) (tree[ind].cnt)

struct Node {
    long long sum, tag;
    int cnt, lind, rind;
} tree[(MAX_N << 1) + 5];
int root = 0, cnt = 1;
long long arr[MAX_N + 5];

int getNode() { return cnt++; }

void UP(int ind) { sum(ind) = sum(lc(ind)) + sum(rc(ind)); }

void DOWN(int ind) {
    if (tag(ind)) {
        tag(lc(ind)) += tag(ind);
        tag(rc(ind)) += tag(ind);
        sum(lc(ind)) += tag(ind) * cnt(lc(ind));
        sum(rc(ind)) += tag(ind) * cnt(rc(ind));
        tag(ind) = 0;
    }
    return;
}

void build(int ind, int l, int r) {
    cnt(ind) = r - l + 1;
    if (l == r) {
        sum(ind) = arr[l];
        return;
    }
    int mid = (l + r) >> 1;
    lc(ind) = getNode();
    rc(ind) = getNode();
    build(lc(ind), l, mid);
    build(rc(ind), mid + 1, r);
    UP(ind);
    return;
}

void modify(int ind, int x, int y, int d, int l, int r) {
    if (x <= l && y >= r) {
        tag(ind) += d;
        sum(ind) += d * cnt(ind);
        return;
    }
    DOWN(ind);
    int mid = (l + r) >> 1;
    if (x <= mid) modify(lc(ind), x, y, d, l, mid);
    if (y > mid) modify(rc(ind), x, y, d, mid + 1, r);
    UP(ind);
    return;
}

long long query(int ind, int x, int y, int l, int r) {
    if (x <= l && y >= r) {
        return sum(ind);
    }
    DOWN(ind);
    int mid = (l + r) >> 1;
    long long ans = 0;
    if (x <= mid) ans += query(lc(ind), x, y, l, mid);
    if (y > mid) ans += query(rc(ind), x, y, mid + 1, r);
    return ans;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%lld", &arr[i]);
    build(root, 1, n);
    while (m--) {
        long long a, b, c, d;
        scanf("%lld%lld%lld", &a, &b, &c);
        if (a == 1) {
            scanf("%lld", &d);
            modify(root, b, c, d, 1, n);
        } else {
            printf("%lld\n", query(root, b, c, 1, n));
        }
    }
    return 0;
}