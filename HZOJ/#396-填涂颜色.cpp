/************************************************************
    File Name : #396-填涂颜色.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/01 19:49:32
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int n, grid[35][35];
int dir[4][2]{{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

void func(int x, int y) {
    for (int i = 0; i < 4; ++i) {
        int tx = x + dir[i][0], ty = y + dir[i][1];
        if (tx > n + 1 || ty > n + 1 || tx < 0 || ty < 0) continue;
        if (grid[tx][ty] == 0) {
            grid[tx][ty] = 3;
            func(tx, ty);
        }
    }
    return;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> grid[i][j];
        }
    }
    func(0, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            j == 1 || cout << ' ';
            if (grid[i][j] == 3) {
                cout << 0;
            } else if (grid[i][j] == 1) {
                cout << 1;
            } else {
                cout << 2;
            }
        }
        cout << endl;
    }
    return 0;
}