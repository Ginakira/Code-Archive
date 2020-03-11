/************************************************************
    File Name : #240- 图形打印四.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2020/03/11 18:03:11
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

char ans[1000][1000];
int num[10] = {0, 1, 3, 9, 27, 81, 243, 729};

void func(int x, int y, int n) {
    if (n == 1) {
        ans[x][y] = 'X';
        return;
    }
    func(x, y, n - 1);                                    // 左上角
    func(x, y + num[n] / 3 * 2, n - 1);                   // 右上角
    func(x + num[n] / 3 * 2, y, n - 1);                   // 左下角
    func(x + num[n] / 3 * 2, y + num[n] / 3 * 2, n - 1);  // 右下角
    func(x + num[n] / 3, y + num[n] / 3, n - 1);          // 中心
    return;
}

int main() {
    func(1, 1, 7);
    int n;
    while (cin >> n && n != -1) {
        for (int i = 1; i <= num[n]; ++i) {
            for (int j = 1; j <= num[n]; ++j) {
                if (ans[i][j] == 'X') {
                    cout << 'X';
                } else {
                    cout << ' ';
                }
            }
            cout << endl;
        }
        cout << "-" << endl;
    }
    return 0;
}