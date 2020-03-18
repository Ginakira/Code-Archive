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
#include <queue>
#include <string>
#include <vector>
using namespace std;

int n, m, k, sx, sy, ans;
char grid[3005][3005];
int solved[3005][3005];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
queue<pair<int, int>> q;

void dfs(int x, int y) {
    int tx, ty;
    for (int i = 0; i < 4; ++i) {
        tx = x + dir[i][0], ty = y + dir[i][1];
        if (grid[tx][ty] && !solved[tx][ty] && (grid[tx][ty] != grid[x][y])) {
            ans++, solved[tx][ty] = 1;
            q.push(make_pair(tx, ty));
            dfs(tx, ty);
        }
    }
    return;
}

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> &(grid[i][1]);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (!solved[i][j]) {
                ans = 1, solved[i][j] = 1;
                q.push(make_pair(i, j));
                dfs(i, j);
                while (!q.empty()) {
                    pair<int, int> temp = q.front();
                    q.pop();
                    solved[temp.first][temp.second] = ans;
                }
            }
        }
    }
    for (int i = 0; i < k; ++i) {
        cin >> sx >> sy;
        cout << solved[sx][sy] << endl;
    }
    return 0;
}