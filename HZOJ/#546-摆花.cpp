/************************************************************
    File Name : #546-摆花.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/25 17:09:43
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 100
#define MOD 1000007
int n, m, num[MAX_N + 5];
int dp[MAX_N + 5][MAX_N + 5];  // 用前i种花摆j盆方案总数

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> num[i];
    for (int i = 0; i <= num[0]; ++i) {
        dp[0][i] = 1;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= m; ++j) {
            for (int k = 0; k <= num[i]; ++k) {
                if (j < k) break;
                dp[i][j] += dp[i - 1][j - k];
                dp[i][j] %= MOD;
            }
        }
    }
    cout << dp[n - 1][m] << endl;
    return 0;
}