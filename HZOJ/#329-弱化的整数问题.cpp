/************************************************************
    File Name : #329-弱化的整数问题.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2020/03/01 19:48:07
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAXN 100000

int c[MAXN + 5];
inline int lowbit(int x) { return x & (-x); }

void add(int x, int val, int n) {
    while (x <= n) c[x] += val, x += lowbit(x);
}

int query(int x) {
    int sum = 0;
    while (x) sum += c[x], x -= lowbit(x);
    return sum;
}

int main() {
    int n, m, pre = 0, now;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> now;
        add(i, now - pre, n);
        pre = now;
    }
    cin >> m;
    string s;
    for (int i = 0; i < m; ++i) {
        cin >> s;
        switch (s[0]) {
            case 'C': {
                int l, r, d;
                cin >> l >> r >> d;
                add(l, d, n);
                add(r + 1, -d, n);
            } break;
            case 'Q': {
                int x;
                cin >> x;
                cout << query(x) << endl;
            } break;
        }
    }
    return 0;
}