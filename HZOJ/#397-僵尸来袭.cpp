/************************************************************
    File Name : #397-僵尸来袭.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2020/03/18 18:30:30
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, m, ans, mmap[105][105];
int dir[4][2]{{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

void dfs(int x, int y) {
    int tx, ty;
    for (int i = 0; i < 4; ++i) {
        tx = x + dir[i][0], ty = y + dir[i][1];
        if (mmap[tx][ty]) {
            mmap[tx][ty] = 0;
            dfs(tx, ty);
        }
    }
    return;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> mmap[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (mmap[i][j]) {
                ans++, mmap[i][j] = 0;
                dfs(i, j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}