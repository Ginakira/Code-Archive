/************************************************************
    File Name : #304-骑士风度的牛.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/01 18:12:03
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

int n, m;
char grid[155][155];
int dir[8][2] = {{1, 2},  {1, -2},  {2, 1},  {2, -1},
                 {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};

queue<node> q;

int main() {
    cin >> m >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'K') q.push({i, j, 0});
        }
    }
    node temp;
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        for (int i = 0; i < 8; ++i) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (x < 1 || y < 1 || x > n || y > m) continue;
            if (grid[x][y] == 'H') {
                cout << temp.step + 1 << endl;
                return 0;
            }
            if (grid[x][y] == '.') {
                grid[x][y] = 0;
                q.push({x, y, temp.step + 1});
            }
        }
    }
    return 0;
}