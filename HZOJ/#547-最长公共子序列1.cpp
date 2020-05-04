/************************************************************
    File Name : #547-最长公共子序列1.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/04 15:54:18
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 5000
int dp[MAX_N + 5][MAX_N + 5];

int main() {
    string x, y;
    cin >> x >> y;
    int lenx = x.size(), leny = y.size();
    for (int i = 1; i <= lenx; ++i) {
        for (int j = 1; j <= leny; ++j) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (x[i - 1] - y[j - 1]) continue;
            dp[i][j] = dp[i - 1][j - 1] + 1;
        }
    }
    cout << dp[lenx][leny] << endl;
    return 0;
}