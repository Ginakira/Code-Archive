/************************************************************
    File Name : #527-飞跃原野.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/01 20:02:39
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct node {
    int x, y, step, remain;
};

int n, m, d;
char grid[105][105];
bool check[105][105][105];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
queue<node> q;

int main() {
    cin >> n >> m >> d;
    for (int i = 1; i <= n; ++i) {
        cin >> &grid[i][1];
    }
    q.push({1, 1, 0, d});
    for (int i = 0; i <= d; ++i) {
        check[1][1][i] = 1;
    }
    node temp;
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            for (int j = 2; j <= temp.remain; ++j) {
                int x = temp.x + j * dir[i][0];
                int y = temp.y + j * dir[i][1];
                if (x == n && y == m) {
                    cout << temp.step + 1 << endl;
                    return 0;
                }
                if (!grid[x][y]) break;
                if (grid[x][y] == 'P' && check[x][y][temp.remain - j] == 0) {
                    check[x][y][temp.remain - j] = 1;
                    q.push({x, y, temp.step + 1, temp.remain - j});
                }
            }
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (x == n && y == m) {
                cout << temp.step + 1 << endl;
                return 0;
            }
            if (grid[x][y] == 'P' && check[x][y][temp.remain] == 0) {
                check[x][y][temp.remain] = 1;
                q.push({x, y, temp.step + 1, temp.remain});
            }
        }
    }
    cout << "impossible\n";
    return 0;
}