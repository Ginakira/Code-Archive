/************************************************************
    File Name : P3865【模板】ST表.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/07 11:37:34
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 100000
#define lc(ind) (ind << 1)
#define rc(ind) (ind << 1 | 1)
#define sum(ind) (tree[ind].sum)

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * f;
}

struct Node {
    int sum;
} tree[(MAX_N << 2) + 5];
int arr[MAX_N + 5];
int root = 1;

void UP(int ind) { sum(ind) = max(sum(lc(ind)), sum(rc(ind))); }

void build(int ind, int l, int r) {
    if (l == r) {
        sum(ind) = arr[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(lc(ind), l, mid);
    build(rc(ind), mid + 1, r);
    UP(ind);
}

int query(int ind, int x, int y, int l, int r) {
    if (x <= l && y >= r) {
        return sum(ind);
    }
    int ans = 0x80000000, mid = (l + r) >> 1;
    if (x <= mid) ans = max(ans, query(lc(ind), x, y, l, mid));
    if (y > mid) ans = max(ans, query(rc(ind), x, y, mid + 1, r));
    return ans;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) arr[i] = read();
    build(root, 1, n);
    int a, b;
    while (m--) {
        a = read();
        b = read();
        printf("%d\n", query(root, a, b, 1, n));
    }
    return 0;
}