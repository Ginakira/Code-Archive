/************************************************************
    File Name : #404-01迷宫简易版.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/20 18:18:44
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#define MAXN 3000
int grid[MAXN + 5][MAXN + 5];
bool visit[MAXN + 5][MAXN + 5];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int n, m, ans = 1;

void dfs(int x, int y, int cnt) {
    if (x < 1 || x > n || y < 1 || y > m) {
        //cout << "OUT OF RANGE\n";
        return;
    }
    if (visit[x][y]) {
        //cout << "VISITED\n";
        return;
    }
    visit[x][y] = 1;
    ans = max(ans, cnt);
    for (int k = 0; k < 4; ++k) {
        int dx = x + dir[k][0];
        int dy = y + dir[k][1];
        /* printf("cnt-%d / x-%d / y-%d / dx-%d / dy-%d / dir-%d\n", cnt, x, y, dx,
               dy, k);
        printf("[x,y] = %d, [dx,dy] = %d\n", grid[x][y], grid[dx][dy]); */
        if (grid[x][y] == grid[dx][dy]) {
            //cout << "CANT REACH\n";
            continue;
        }/*  else {
            cout << "GO!\n";
        } */
        dfs(dx, dy, cnt + 1);
    }
    visit[x][y] = 0;
    return;
}

int main() {
    memset(grid, 0, sizeof(grid));
    memset(visit, 0, sizeof(visit));
    char tmp;
    cin >> n >> m;
    getchar();
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            tmp = getchar();
            grid[i][j] = tmp - '0';
        }
        getchar();
    }
    int sx, sy;
    cin >> sx >> sy;
    dfs(sx, sy, 1);
    cout << ans << endl;
    return 0;
}