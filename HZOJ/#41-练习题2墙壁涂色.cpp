/************************************************************
    File Name : #41-练习题2墙壁涂色.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/26 20:30:15
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// i j 代表首尾颜色

int f[1005][15][15];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            f[1][i][j] = (i == j);
        }
    }

    for (int t = 2; t <= n; ++t) {
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < k; ++j) {
                for (int l = 0; l < k; ++l) {
                    if (l - j) f[t][i][j] += f[t - 1][i][l];
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            if (i - j) ans += f[n][i][j];
        }
    }
    cout << ans << endl;

    return 0;
}