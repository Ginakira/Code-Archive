/************************************************************
    File Name : #305-乳草的入侵.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/01 19:08:52
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

int n, m, sx, sy;
char grid[105][105];
int dir[8][2] = {{1, 0}, {0, 1},  {-1, 0}, {0, -1},
                 {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
queue<node> q;

int main() {
    cin >> m >> n >> sy >> sx;
    for (int i = 1; i <= n; ++i) {
        cin >> &grid[i][1];
    }
    q.push({n - sx + 1, sy, 0});
    grid[n - sx + 1][sy] = '*';
    int ans;
    node temp;
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        ans = temp.step;
        for (int i = 0; i < 8; ++i) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (grid[x][y] == '.') {
                grid[x][y] = '*';
                q.push({x, y, temp.step + 1});
            }
        }
    }
    cout << ans << endl;
    return 0;
}