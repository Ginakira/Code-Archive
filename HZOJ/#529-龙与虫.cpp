/************************************************************
    File Name : #529-龙与虫.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/01 20:39:59
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct node {
    int x, y, step;
};

int n, m;
int check[150][150];
char grid[150][150];
int dir[8][2] = {{0, 1}, {1, 0},  {0, -1}, {-1, 0},
                 {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int func() {
    int a, b, c, d;
    cin >> c >> d >> a >> b;
    if (!a) return 0;
    memset(check, 0, sizeof(check));
    for (int i = 0; i < 8; ++i) {
        for (int j = 1; 1; ++j) {
            int x = c + j * dir[i][0];
            int y = d + j * dir[i][1];
            if (grid[x][y] != 'O') break;
            check[x][y] = 2;
        }
    }
    check[c][d] = 2;
    if (check[a][b] == 2) {
        cout << 0 << endl;
        return 1;
    }
    queue<node> q;
    q.push({a, b, 0});
    check[a][b] = 1;
    node temp;
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (check[x][y] == 2) {
                cout << temp.step + 1 << endl;
                return 1;
            }
            if (grid[x][y] == 'O' && check[x][y] != 1) {
                check[x][y] = 1;
                q.push({x, y, temp.step + 1});
            }
        }
    }
    cout << "Impossible!\n";
    return 1;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> &grid[i][1];
    }
    while (func())
        ;
    return 0;
}