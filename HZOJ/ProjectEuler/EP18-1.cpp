/************************************************************
    File Name : EP18-1.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/28 16:18:30
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#define MAX_N 20

int val[MAX_N][MAX_N];
int keep[MAX_N][MAX_N];

int dfs(int i, int j, int n) {
    if (i + 1 == n) return val[i][j];
    if (keep[i][j]) return keep[i][j];
    int val1 = dfs(i + 1, j, n);
    int val2 = dfs(i + 1, j + 1, n);
    return keep[i][j] = max(val1, val2) + val[i][j];
}

int main() {
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j <= i; ++j) {
            cin >> val[i][j];
        }
    }
    cout << dfs(0, 0, 15) << endl;
    return 0;
}