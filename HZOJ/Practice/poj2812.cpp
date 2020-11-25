/************************************************************
    File Name : poj2812.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/11/25 09:45:24
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 5000

struct Point {
    int x, y;
};

Point p[MAX_N + 5] = {{0, 0}};
bool mark[MAX_N + 5][MAX_N + 5] = {{0}};
int R, C, N;
int ans = 0;

bool outside(int x, int y) { return x <= 0 || y <= 0 || x > R || y > C; };

void count(int a, int b) {
    int dx = p[b].x - p[a].x;
    int dy = p[b].y - p[a].y;

    if (!outside(p[a].x - dx, p[a].y - dy)) return;

    if (p[a].x + ans * dx <= 0 || p[a].x + ans * dx > R ||
        p[a].y + ans * dy <= 0 || p[a].y + ans * dy > C)
        return;

    int k = 2;
    int x1 = p[b].x + dx;
    int y1 = p[b].y + dy;

    while (!outside(x1, y1) && mark[x1][y1]) {
        ++k;
        x1 += dx, y1 += dy;
    }

    if (outside(x1, y1) && k > ans) ans = k;
}

int main() {
    cin >> R >> C >> N;
    for (int i = 0; i < N; ++i) {
        cin >> p[i].x >> p[i].y;
        mark[p[i].x][p[i].y] = true;
    }

    sort(p, p + N, [](const Point &a, const Point &b) -> bool {
        return a.x > b.x || (a.x == b.x && a.y > b.y);
    });

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            count(i, j);
        }
    }
    if (ans < 3) {
        ans = 0;
    }
    cout << ans << endl;
    return 0;
}