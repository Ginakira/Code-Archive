/************************************************************
    File Name : #404-01迷宫简易版.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2020/03/18 18:42:52
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, m, sx, sy, ans = 1;
char grid[3005][3005];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void dfs(int x, int y) {
    int tx, ty;
    if (!grid[x][y]) return;
    for (int i = 0; i < 4; ++i) {
        tx = x + dir[i][0], ty = y + dir[i][1];
        if (grid[tx][ty] != grid[x][y]) {
            ans++;
            dfs(tx, ty);
        }
    }
    grid[tx][ty] = 0;
    return;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> &(grid[i][1]);
    }
    cin >> sx >> sy;
    dfs(sx, sy);
    cout << ans << endl;
    return 0;
}