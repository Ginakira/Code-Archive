/************************************************************
    File Name : #535-瓷砖.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2020/03/18 18:13:01
************************************************************/
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct node {
    int x, y;
};

int h, w, ans = 1;
int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
char grid[55][55];
queue<node> que;

int main() {
    cin >> h >> w;
    for (int i = 1; i <= w; ++i) {
        for (int j = 1; j <= h; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == '@') {
                que.push({i, j});
            }
        }
    }
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; ++i) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (grid[x][y] == '.') {
                grid[x][y] = 0;
                ans++;
                que.push({x, y});
            }
        }
    }
    cout << ans << endl;
    return 0;
}