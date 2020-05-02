/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/02 23:00:27
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 1000
int f[MAX_N + 5][MAX_N + 5];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            cin >> f[i][j];
        }
    }

    for (int i = n - 1; i > 0; --i) {
        for (int j = 1; j <= i; ++j) {
            f[i][j] += max(f[i + 1][j], f[i + 1][j + 1]);
        }
    }
    cout << f[1][1] << endl;
    return 0;
}