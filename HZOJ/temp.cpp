/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/18 21:53:29
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;
#define MAX_N 100000
#define lc(ind) (ind << 1)
#define rc(ind) (ind << 1 | 1)
#define tag(ind) (tree[ind].tag)
#define sum(ind) (tree[ind].sum)
#define cnt(ind) (tree[ind].cnt)

struct Node {
    LL sum;
    int tag, cnt;
} tree[(MAX_N << 2) + 5];
int arr[MAX_N + 5];
int root = 1;

void UP(int ind) {
    sum(ind) = sum(lc(ind)) + sum(rc(ind));
    return;
}

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
    build(lc(ind), l, mid);
    build(rc(ind), mid + 1, r);
    UP(ind);
    return;
}

void modify(int ind, int x, int y, int k, int l, int r) {
    if (x <= l && y >= r) {
        tag(ind) += k;
        sum(ind) += k * cnt(ind);
        return;
    }
    DOWN(ind);
    int mid = (l + r) >> 1;
    if (x <= mid) modify(lc(ind), x, y, k, l, mid);
    if (y > mid) modify(rc(ind), x, y, k, mid + 1, r);
    UP(ind);
    return;
}

LL query(int ind, int x, int y, int l, int r) {
    if (x <= l && r <= y) {
        return sum(ind);
    }
    DOWN(ind);
    int mid = (l + r) >> 1;
    LL ans = 0;
    if (x <= mid) ans += query(lc(ind), x, y, l, mid);
    if (y > mid) ans += query(rc(ind), x, y, mid + 1, r);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    build(root, 1, n);
    while (m--) {
        int opt, x, y, k;
        cin >> opt >> x >> y;
        if (opt == 1) {
            cin >> k;
            modify(root, x, y, k, 1, n);
        } else {
            cout << query(root, x, y, 1, n) << endl;
        }
    }
    return 0;
}