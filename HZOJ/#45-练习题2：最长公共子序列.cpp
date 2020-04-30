/************************************************************
    File Name : #45-练习题2：最长公共子序列.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/30 20:19:53
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 1000

int dp[MAX_N + 5][MAX_N + 5];  // s1选前i位s2选前j位最长公共序列长度
string s1, s2;

int main() {
    cin >> s1 >> s2;
    for (int i = 1; i <= s1.size(); ++i) {
        for (int j = 1; j <= s2.size(); ++j) {
            if (s1[i - 1] - s2[j - 1]) {  // 如果i j位字符不同
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                continue;
            }
            dp[i][j] = dp[i - 1][j - 1] + 1;
        }
    }
    cout << dp[s1.size()][s2.size()] << endl;

    return 0;
}