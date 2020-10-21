/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/11/02 16:10:41
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 100

int dir[8][2] = {{1, 0},  {-1, 0}, {0, 1}, {0, -1},
                 {1, -1}, {-1, 1}, {1, 1}, {-1, -1}};

char grid[MAX_N + 5][MAX_N + 5];
char ans[MAX_N + 5][MAX_N + 5];

int n, m;

void calc(int cur_i, int cur_j) {
    if (grid[cur_i][cur_j] == '*') {
        ans[cur_i][cur_j] = '*';
        return;
    }
    int cnt = 0;
    for (int i = 0; i < 8; ++i) {
        int new_i = cur_i + dir[i][0], new_j = cur_j + dir[i][1];
        if (new_i < 0 || new_i >= n || new_j < 0 || new_j >= m) {
            continue;
        }
        if (grid[new_i][new_j] == '*') {
            cnt++;
        }
    }
    ans[cur_i][cur_j] = cnt + '0';
    return;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            calc(i, j);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}