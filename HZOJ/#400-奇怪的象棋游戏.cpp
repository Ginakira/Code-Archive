/************************************************************
    File Name : #400-奇怪的象棋游戏.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/01 20:20:44
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct node {
    int x, y, step;
};

int dir[12][2] = {{1, 2},   {-1, 2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
                  {-1, -2}, {1, -2}, {2, 2}, {-2, 2}, {2, -2}, {-2, -2}};

void solve(int sx, int sy) {
    queue<node> q;
    bool grid[505][505] = {{0}};
    q.push({sx, sy, 0});
    grid[sx][sy] = true;
    node temp;
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        for (int i = 0; i < 12; ++i) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (x < 1 || y < 1 || x > 500 || y > 500 || grid[x][y]) continue;
            if (x == 1 && y == 1) {
                cout << temp.step + 1 << endl;
                return;
            }
            grid[x][y] = true;
            q.push({x, y, temp.step + 1});
        }
    }
}

int main() {
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    solve(x1, y1);
    solve(x2, y2);
    return 0;
}