/************************************************************
    File Name : #536-最大黑色区域.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2020/03/15 22:40:30
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int ans = 0, n, m;
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char grid[150][150] = {{0}};

int dfs(int x, int y) {
    int tx, ty, cnt = 1;
    grid[x][y] = '3';
    for (int i = 0; i < 4; ++i) {
        tx = x + dir[i][0], ty = y + dir[i][1];
        if (tx >= n || ty >= m || tx < 0 || ty < 0) continue;
        if (grid[tx][ty] == '1') {
            grid[tx][ty] = '3';
            cnt += dfs(tx, ty);
        }
    }
    return cnt;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            (grid[i][j] == '1') && (ans = max(dfs(i, j), ans));
        }
    }
    cout << ans << endl;
    return 0;
}