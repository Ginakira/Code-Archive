/************************************************************
    File Name : #343-最长公共上升子序列.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/04 00:33:38
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 3000
int a[MAX_N + 5], b[MAX_N + 5];
int dp[MAX_N + 5][MAX_N + 5];
// a用前i位，b用前j位，以a[i]为末尾的最长公共上升子序列
int ans = 0;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = dp[i][j - 1];
            if (a[i] - b[j]) continue;
            dp[i][j] = max(dp[i][j], 1);
            for (int k = 1; k < i; ++k) {
                if (a[k] >= a[i]) continue;
                dp[i][j] = max(dp[i][j], dp[k][j - 1] + 1);
            }
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}