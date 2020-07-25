/************************************************************
    File Name : #607-数塔问题.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/07/23 20:58:33
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 100

int main() {
    int n, arr[MAX_N + 5][MAX_N + 5];
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            cin >> arr[i][j];
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        for (int j = 1; j <= i; ++j) {
            arr[i][j] += max(arr[i + 1][j], arr[i + 1][j + 1]);
        }
    }

    cout << arr[1][1] << endl;
    return 0;
}