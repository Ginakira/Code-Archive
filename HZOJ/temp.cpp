/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/02 11:51:14
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 32767
int dp[MAX_N + 5];

int main() {
    int n;
    cin >> n;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = (dp[i - 1] + 2 - 1) % i + 1;
    }
    int x = n;
    while (dp[x] - x) x = dp[x];
    cout << n + x << endl;
    return 0;
}