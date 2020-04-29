/************************************************************
    File Name : #43-数字三角形-DP copy.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/29 20:13:14
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, ans[1005][1005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            cin >> ans[i][j];
        }
    }
    for (int i = n; i > 0; --i) {
        for (int j = 1; j <= i; ++j) {
            ans[i][j] += max(ans[i + 1][j + 1], ans[i + 1][j]);
        }
    }
    cout << ans[1][1] << endl;
    return 0;
}