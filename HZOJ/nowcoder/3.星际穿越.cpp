/************************************************************
    File Name : 3.星际穿越.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/08/26 16:37:17
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, num[10][10][10], ans, mark[10][10][10], sx, sy, sz;
int dir[6][3] = {{1, 0, 0},  {-1, 0, 0}, {0, 1, 0},
                 {0, -1, 0}, {0, 0, 1},  {0, 0, -1}};

int func(int x, int y, int z) {
    int t = 0;
    for (int i = 0; i < 6; ++i) {
        int xx = x = dir[i][0];
        int yy = y + dir[i][1];
        int zz = z + dir[i][2];
        if (xx < 0 || yy < 0 || zz < 0 || xx >= n || yy >= n || zz >= n) {
            continue;
        }
        if (num[x][y][z] > num[xx][yy][zz] && mark[xx][yy][zz] == 0) {
            mark[xx][yy][zz] = 1;
            t = max(t, func(xx, yy, zz));
            mark[xx][yy][zz] = 0;
        }
    }
    return t + num[x][y][z];
}

int main() {
    cin >> n;
    for (int i = 0; i < n * n * n; ++i) {
        int x, y, z, t;
        cin >> x >> y >> z >> t;
        num[x][y][z] = t;
        if (num[sx][sy][sz] < t) {
            sx = x, sy = y, sz = z;
        }
    }
    ans = func(sx, sy, sz);
    cout << ans << endl;
    return 0;
}