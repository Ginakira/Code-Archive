/************************************************************
    File Name : #406-水坑数量.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2020/03/18 19:01:02
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, m, ans;
char grid[3005][3005];
int dir[8][2] = {{0, 1},  {0, -1}, {1, 0}, {-1, 0},
                 {1, -1}, {-1, 1}, {1, 1}, {-1, -1}};

void dfs(int x, int y) {
    int tx, ty;
    for (int i = 0; i < 8; ++i) {
        tx = x + dir[i][0], ty = y + dir[i][1];
        if (grid[tx][ty] == '#') grid[tx][ty] = '.', dfs(tx, ty);
    }
    return;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> &(grid[i][1]);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (grid[i][j] == '#') {
                grid[i][j] = '.', ans++;
                dfs(i, j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}