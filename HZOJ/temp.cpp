/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/09/14 17:47:57
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int dp[50][50];
    int maxLen = 0, maxEnd = 0;
    for (int i = 0; i < s1.length(); ++i) {
        for (int j = 0; j < s2.length(); ++j) {
            if (s1[i] == s2[j]) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
            } else {
                dp[i][j] = 0;
            }
            if (dp[i][j] > maxLen) {
                maxLen = dp[i][j];
                maxEnd = i;
            }
        }
    }
    cout << endl;
    cout << maxLen << endl;
    cout << maxEnd << endl;
    cout << s1.substr(maxEnd - maxLen + 1, maxLen) << endl;
    return 0;
}