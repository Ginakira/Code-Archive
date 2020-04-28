/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/28 17:13:59
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

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
                }
            }
        }
    }

    return 0;
}