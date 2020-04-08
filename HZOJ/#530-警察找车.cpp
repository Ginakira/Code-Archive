/************************************************************
    File Name : #530-警察找车.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/08 18:15:38
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int x, y;
};

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int n, m, cnt;
char grid[55][55];
bool visited[55][55];

int main() {
    ios_base::sync_with_stdio(false);
    queue<Node> que;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == '*') {
                que.push({i, j});
                grid[i][j] = '.';
                visited[i][j] = true;
            }
        }
    }
    cin >> cnt;
    while (cnt--) {
        string t;
        cin >> t;
        int dir_num;
        if (t == "NORTH") {
            dir_num = 0;
        } else if (t == "SOUTH") {
            dir_num = 1;
        } else if (t == "WEST") {
            dir_num = 2;
        } else {
            dir_num = 3;
        }
        memset(visited, 0, sizeof(visited));
        int times = que.size();
        Node temp;
        for (int i = 0; i < times; ++i) {
            temp = que.front();
            que.pop();
            for (int j = 1;; ++j) {
                int x = temp.x + j * dir[dir_num][0];
                int y = temp.y + j * dir[dir_num][1];
                if (grid[x][y] != '.') break;
                if (!visited[x][y]) {
                    que.push({x, y});
                    visited[x][y] = true;
                }
            }
        }
    }

    Node temp;
    while (!que.empty()) {
        temp = que.front();
        que.pop();
        grid[temp.x][temp.y] = '*';
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << grid[i][j];
        }
        cout << endl;
    }
    return 0;
}