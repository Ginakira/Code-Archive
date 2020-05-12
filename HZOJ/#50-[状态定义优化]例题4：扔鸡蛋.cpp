/************************************************************
    File Name : #50-[状态定义优化]例题4：扔鸡蛋.cpp
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
typedef long long LL;
#define MAX_N 32
#define MAX_M 65536
LL dp[MAX_N + 5][MAX_M + 5];
// dp[n][k] n个鸡蛋扔k次最多能测多少楼
// dp[n][k] = dp[n - 1][k - 1] + dp[n][k - 1] + 1

int main() {
    LL n, m;
    cin >> n >> m;
    if (n == 1) {
        cout << m << endl;
        return 0;
    }

    for (int k = 1; k <= MAX_M; ++k) dp[1][k] = k;

    for (int i = 2; i <= n; ++i) {
        for (int k = 1; k <= MAX_M; ++k) {
            dp[i][k] = dp[i - 1][k - 1] + dp[i][k - 1] + 1;
        }
    }
    int p = 1;
    while (dp[n][p] < m) p++;
    cout << p << endl;
    return 0;
}