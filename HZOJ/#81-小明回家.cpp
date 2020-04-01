/************************************************************
    File Name : #81-小明回家.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/01 19:23:53
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
    bool flag;
};

int n, m;
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char grid[2005][2005];
char check[2005][2005];
queue<node> q;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') {
                check[i][j] = 1;
                q.push({i, j, 0, false});
            }
        }
    }
    node temp;
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (!temp.flag && (check[x][y] & 1)) continue;
            if (temp.flag && (check[x][y] & 2)) continue;
            if (temp.flag && grid[x][y] == 'T') {
                cout << temp.step + 1 << endl;
                return 0;
            }
            if (grid[x][y] == '.' || grid[x][y] == 'S' || grid[x][y] == 'T') {
                q.push({x, y, temp.step + 1, temp.flag});
                check[x][y] += (int)temp.flag + 1;
            } else if (grid[x][y] == 'P') {
                q.push({x, y, temp.step + 1, true});
                check[x][y] = 3;
            }
        }
    }
    return 0;
}