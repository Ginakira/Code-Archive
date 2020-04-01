/************************************************************
    File Name : #303-矩阵距离一.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/01 18:33:26
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
char grid[1005][1005];
int ans[1005][1005];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
queue<node> q;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == '1') {
                q.push({i, j, 0});
                ans[i][j] = -1;
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
            if (x < 1 || y < 1 || x > n || y > m || ans[x][y]) continue;
            ans[x][y] = temp.step + 1;
            q.push({x, y, temp.step + 1});
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            j != 1 && cout << ' ';
            if (ans[i][j] == -1) {
                cout << 0;
            } else {
                cout << ans[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}