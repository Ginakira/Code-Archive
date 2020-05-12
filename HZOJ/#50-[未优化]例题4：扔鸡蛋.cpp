/************************************************************
    File Name : #50-[未优化]例题4：扔鸡蛋.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/12 18:54:21
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 32
#define MAX_M 10000
int dp[MAX_N + 5][MAX_M + 5];
int f[MAX_N + 5][MAX_M + 5];  // i枚鸡蛋测j层楼 第一枚在哪里扔

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (i == 1) {
                dp[i][j] = j;
                f[i][j] = 1;
                continue;
            }
            dp[i][j] = j;
            f[i][j] = 1;
            for (int k = 1; k <= j; ++k) {
                int val = max(dp[i - 1][k - 1], dp[i][j - k]) + 1;
                if (val < dp[i][j]) {
                    f[i][j] = k;
                    dp[i][j] = val;
                }
            }
        }
    }
    cout << dp[n][m] << endl;
    int sum = 0;
    while (sum < m) {
        cout << sum + f[n][m - sum] << ' ';
        sum += f[n][m - sum];
    }
    cout << endl;
    return 0;
}