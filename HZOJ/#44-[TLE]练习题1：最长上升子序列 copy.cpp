/************************************************************
    File Name : #44-练习题1：最长上升子序列.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/30 19:19:31
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 1000000

int dp[MAX_N + 5];
int a[MAX_N + 5];

int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        dp[i] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            if (a[j] >= a[i]) continue;
            dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;

    return 0;
}