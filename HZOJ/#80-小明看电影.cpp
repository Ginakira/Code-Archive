/************************************************************
    File Name : #80-小明看电影.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/03/25 20:35:21
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
char grid[505][505];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
queue<node> que;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 's') {
                que.push({i, j, 0});
            }
        }
    }
    node temp;
    while (!que.empty()) {
        temp = que.front();
        que.pop();
        for (int i = 0; i < 4; ++i) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (grid[x][y] == 'g') {
                cout << temp.step + 1 << endl;
                return 0;
            } else if (grid[x][y] == '.') {
                grid[x][y] = 0;
                que.push({x, y, temp.step + 1});
            }
        }
    }
    cout << "No\n";
    return 0;
}