/************************************************************
    File Name : #52-例题6：古老的打字机.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/30 20:45:29
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 1000000
typedef long long LL;

inline LL S(LL x) { return x * x; }

LL dp[MAX_N + 5];
LL c[MAX_N + 5];

int main() {
    int n, M;
    cin >> n >> M;
    c[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
        c[i] += c[i - 1];
    }
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1] + S(c[i] - c[i - 1]) + M;
        for (int j = 0; j < i - 1; ++j) {
            dp[i] = min(dp[i], dp[j] + S(c[i] - c[j]) + M);
        }
    }
    cout << dp[n] << endl;

    return 0;
}