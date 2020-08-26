/************************************************************
    File Name : 2.工作安排.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/08/26 16:23:56
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 1000

int low[MAX_N + 5], high[MAX_N + 5];
int dp[MAX_N + 5];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> low[i] >> high[i];
    }

    for (int i = 1; i <= n; ++i) {
        dp[i] = max(dp[(i - 1) < 0 ? 0 : (i - 1)] + low[i],
                    dp[(i - 2) < 0 ? 0 : (i - 2)] + high[i]);
    }
    cout << dp[n] << endl;
    return 0;
}