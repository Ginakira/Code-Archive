/************************************************************
    File Name : #398-马的遍历.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/01 18:48:21
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

int grid[405][405];
int dir[8][2] = {{1, 2},  {1, -2},  {2, 1},  {2, -1},
                 {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};
queue<node> q;

int main() {
    int n, m, sx, sy;
    cin >> n >> m >> sx >> sy;
    grid[sx][sy] = -1;
    q.push({sx, sy, 0});
    node temp;
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        for (int i = 0; i < 8; ++i) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (x < 1 || y < 1 || x > n || y > m || grid[x][y]) continue;
            grid[x][y] = temp.step + 1;
            q.push({x, y, temp.step + 1});
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            j > 1 && cout << ' ';
            if (grid[i][j] == -1) {
                cout << 0;
            } else if (grid[i][j] == 0) {
                cout << -1;
            } else {
                cout << grid[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}