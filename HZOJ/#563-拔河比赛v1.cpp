/************************************************************
    File Name : #563-拔河比赛v1.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/19 11:02:55
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// f[i][j] 前i个人拼凑出j重量 1可以拼出 0不可以
// f[i][j] = f[i - 1][j] 或 f[i - 1][j - weight(i)]

#define MAX_N 500
#define MAX_M 500000
int f[MAX_M + 5];
int val[MAX_N + 5];

int main() {
    f[0] = 1;
    int n, S = 0, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> val[i];
        S += val[i];
    }
    sum = S >> 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = sum; j >= 0; --j) {
            // f[j] = f[i - 1][j];
            if (j >= val[i]) f[j] |= f[j - val[i]];
        }
    }
    int ans = 0;
    for (int i = 0; i <= sum; ++i) {
        if (f[i]) ans = i;
    }
    cout << ans << " " << S - ans << endl;
    return 0;
}