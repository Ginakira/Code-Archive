/************************************************************
    File Name : test.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2022/03/27 19:02:06
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int calculate_area_count(const vector<vector<int>> &matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int area_count = 0;

    const int dirs[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    function<void(int, int)> dfs_helper = [&](int x, int y) {
        if (vis[x][y]) return;
        vis[x][y] = true;
        for (auto dir : dirs) {
            int tx = x + dir[0], ty = y + dir[1];
            if (tx < 0 || tx >= n || ty < 0 || ty >= m || vis[tx][ty] == true) {
                continue;
            }
            if (matrix[tx][ty] - matrix[x][y] >= 2) {
                continue;
            }
            dfs_helper(tx, ty);
        }
    };

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (vis[i][j]) continue;
            dfs_helper(i, j);
            ++area_count;
        }
    }

    return area_count;
}

int main() {
    vector<vector<int>> cases{{1, 2}, {4, 3}};
    int result = calculate_area_count(cases);
    cout << result << endl;
    return 0;
}