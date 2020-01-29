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

long long dp[505] = {0, 0, 1, 1, 1};

int solve(int n) {
    for (int i = 5; i <= n; ++i) {
        dp[i] = dp[i - 2] + dp[i - 3];
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}