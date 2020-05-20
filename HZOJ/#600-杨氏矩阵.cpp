/************************************************************
    File Name : #600-杨氏矩阵.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/20 20:28:30
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 3000

int a[MAX_N + 5][MAX_N + 5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, t;
    cin >> n >> m >> t;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    int i = 1, j = m;
    while (i  && j) {
        if (a[i][j] == t) break;
        if (a[i][j] > t) {
            j--;
        } else {
            i++;
        }
    }
    cout << i << ' ' << j << endl;
    return 0;
}