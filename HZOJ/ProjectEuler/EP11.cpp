/************************************************************
    File Name : EP11.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/19 20:15:47
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#define MAXN 20

int grid[MAXN + 5][MAXN + 5];
int dir[4][2] = {{-1, 1}, {-1, 0}, {-1, 1}, {0, 1}};

int calc(int x, int y) {
    int ans = 0;
    for (int k = 0; k < 4; ++k) {
        int p = 1;
        for (int step = 0; step < 4; ++step) {
            int dx = x + dir[k][0] * step;
            int dy = y + dir[k][1] * step;
            if (dx < 0 || dx >= MAXN) break;
            if (dy < 0 || dy >= MAXN) break;
            p *= grid[dx][dy];
        }
        if (p > ans) ans = p;
    }
    return ans;
}

int main() {
    for (int i = 0; i < MAXN; ++i) {
        for (int j = 0; j < MAXN; ++j) {
            scanf("%d", &grid[i][j]);
        }
    }
    int ans = 0, p;
    for (int i = 0; i < MAXN; ++i) {
        for (int j = 0; j < MAXN; ++j) {
            p = calc(i, j);
            if (p > ans) ans = p;
        }
    }
    printf("%d\n", ans);
    return 0;
}