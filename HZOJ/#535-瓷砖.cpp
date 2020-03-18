/************************************************************
    File Name : #535-瓷砖.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2020/03/18 18:13:01
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int h, w, sx, sy, ans = 1;
int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
char matrix[55][55];

void dfs(int x, int y) {
    int tx, ty;
    for (int i = 0; i < 4; ++i) {
        tx = x + dir[i][0], ty = y + dir[i][1];
        if (matrix[tx][ty] == '.') {
            matrix[tx][ty] = 0, ans++;
            dfs(tx, ty);
        }
    }
    return;
}

int main() {
    cin >> h >> w;
    for (int i = 1; i <= w; ++i) {
        for (int j = 1; j <= h; ++j) {
            cin >> matrix[i][j];
            if (matrix[i][j] == '@') sx = i, sy = j;
        }
    }
    dfs(sx, sy);
    cout << ans << endl;
    return 0;
}