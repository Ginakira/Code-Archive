/************************************************************
    File Name : 搜索-马走日.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/19 20:35:12
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#define MAXN 10

int arr[MAXN + 5][MAXN + 5];
int dir[8][2] = {{-2, 1},  {-2, -1}, {2, -1}, {2, 1},
                 {-1, -2}, {-1, 2},  {1, -2}, {1, 2}};
int n, m, ans = 0;

void dfs(int x, int y, int cnt) {
    if (x < 0 || x >= n || y < 0 || y >= m) return;
    if (arr[x][y]) return;
    if (cnt == n * m) {
        ans++;
        return;
    }
    arr[x][y] = 1;
    for (int k = 0; k < 8; ++k) {
        int dx = x + dir[k][0];
        int dy = y + dir[k][1];
        dfs(dx, dy, cnt + 1);
    }
    arr[x][y] = 0;
}

int main() {
    int T, sx, sy;
    scanf("%d", &T);
    while (T--) {
        ans = 0;
        memset(arr, 0, sizeof(arr));
        scanf("%d%d%d%d", &n, &m, &sx, &sy);
        int cnt = 1;
        dfs(sx, sy, cnt);
        printf("%d\n", ans);
    }
    return 0;
}