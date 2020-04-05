/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/04 12:44:56
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

long long C[1000005];

int lowbit(int x) { return x & (-x); }

void add(int x, int val, int n) {
    while (x <= n) C[x] += val, x += lowbit(x);
    return;
}

long long query(int x) {
    long long sum = 0;
    while (x) sum += C[x], x -= lowbit(x);
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, temp;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> temp;
        add(i, temp, n);
    }
    int op, a, b;
    while (m--) {
        cin >> op >> a >> b;
        if (op == 1) {
            add(a, b, n);
        } else if (op == 2) {
            cout << query(b) - query(a - 1) << endl;
        }
    }
    return 0;
}