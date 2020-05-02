/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/02 11:14:50
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_M 20
#define MAX_N 10000
int arr[MAX_M + 5];
int dp[MAX_M + 5][MAX_N + 5];

int main() {
    int n, m;
    cin >> m >> n;
    for (int i = 1; i <= m; ++i) {
        cin >> arr[i];
        dp[i][0] = 1;
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j >= arr[i]) dp[i][j] += dp[i][j - arr[i]];
            dp[i][j] %= 9973;
        }
    }
    cout << dp[m][n] << endl;
    return 0;
}