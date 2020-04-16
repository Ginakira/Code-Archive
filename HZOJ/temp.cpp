/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/15 22:03:58
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define MAX_N 10000
#define lc(ind) (ind << 1)
#define rc(ind) (ind << 1 | 1)
#define sum(ind) (tree[ind].sum)

struct node {
    int sum;
} tree[(MAX_N << 2) + 5];
int arr[MAX_N + 5];

int root = 1;

void UP(int ind) {
    sum(ind) = sum(lc(ind)) + sum(rc(ind));
    return;
}

void build(int ind, int l, int r) {
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

void modify(int ind, int x, int y, int l, int r) {
    if (l == r) {
        sum(ind) = y;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid)
        modify(lc(ind), x, y, l, mid);
    else
        modify(rc(ind), x, y, mid + 1, r);
    UP(ind);
    return;
}

int query(int ind, int x, int y, int l, int r) {
    if (x <= l && y >= r) {
        return sum(ind);
    }
    int ans = 0, mid = (l + r) >> 1;
    if (l <= mid) ans += query(lc(ind), x, y, l, mid);
    if (y > mid) ans += query(rc(ind), x, y, mid + 1, r);
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> arr[i];
    build(root, 1, n);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
            modify(root, b, c, 1, n);
        else {
            cout << query(root, b, c, 1, n) << endl;
        }
    }
    return 0;
}