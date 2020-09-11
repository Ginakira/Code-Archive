/************************************************************
    File Name : 1-4-2.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/09/09 09:36:00
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 20

int main() {
    int n, m;
    cin >> n >> m;
    int matrix[MAX_N][MAX_N];
    int matrix_t[MAX_N][MAX_N];
    int ans[MAX_N][MAX_N] = {{0}};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }
    // TRANSPOSITION
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            matrix_t[i][j] = matrix[j][i];
        }
    }
    // MULTIPLE
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < n; ++k) {
                ans[i][j] += matrix_t[i][k] * matrix[k][j];
            }
        }
    }
    // PRINT
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}