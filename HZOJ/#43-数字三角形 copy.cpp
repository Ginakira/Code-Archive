/************************************************************
    File Name : #43-数字三角形.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/28 18:04:31
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#define MAX_N 1000

int val[MAX_N + 5][MAX_N + 5];
int keep[MAX_N + 5][MAX_N + 5];

int dfs(int i, int j, int n) {
    if (i + 1 >= n) return val[i][j];
    if (keep[i][j]) return keep[i][j];
    int val1 = dfs(i + 1, j, n);
    int val2 = dfs(i + 1, j + 1, n);
    return keep[i][j] = max(val1, val2) + val[i][j];
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cin >> val[i][j];
        }
    }
    cout << dfs(0, 0, n) << endl;
    return 0;
}