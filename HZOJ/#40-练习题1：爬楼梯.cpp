/************************************************************
    File Name : #40-练习题1：爬楼梯.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2020/01/28 18:33:22
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int dp[505][100];

void large_add(int a[], int ans[]) {
    ans[0] = a[0];
    for (int i = 1; i <= ans[0]; ++i) {
        ans[i] += a[i];
    }
    for (int i = 1; i <= ans[0]; ++i) {
        if (ans[i] < 10) continue;
        ans[i + 1] += ans[i] / 10;
        ans[i] %= 10;
        ans[0] += (i == ans[0]);
    }
    return;
}

void solve(int n) {
    dp[0][0] = 1, dp[1][0] = 1;
    dp[2][0] = 1, dp[2][1] = 1;
    dp[3][0] = 1, dp[3][1] = 1;
    for (int i = 4; i <= n; ++i) {
        large_add(dp[i - 2], dp[i]);
        large_add(dp[i - 3], dp[i]);
    }
    return;
}

int main() {
    int n;
    cin >> n;
    solve(n);
    for (int i = dp[n][0]; i > 0; --i) {
        cout << dp[n][i];
    }
    return 0;
}