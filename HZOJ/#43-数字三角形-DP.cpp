/************************************************************
    File Name : #43-数字三角形-DP.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/28 18:09:02
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#define MAXN 1000

int val[MAXN + 5][MAXN + 5];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cin >> val[i][j];
        }
    }
    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) {
            val[i][j] += max(val[i + 1][j], val[i + 1][j + 1]);
        }
    }
    cout << val[0][0] << endl;
    return 0;
}