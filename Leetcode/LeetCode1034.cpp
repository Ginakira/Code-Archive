// LeetCode 1034 边界着色

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   private:
    const int dir[4][2]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool is_border(vector<vector<int>> &grid, int x, int y) {
        if (x == 0 || x == m_ - 1 || y == 0 || y == n_ - 1) {
            return true;
        };
        for (int i = 0; i < 4; ++i) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (grid[x][y] != grid[nx][ny]) {
                return true;
            }
        }
        return false;
    }

    void dfs(vector<vector<int>> &grid, vector<vector<int>> &visited,
             vector<tuple<int, int>> &to_color, int x, int y,
             int origin_color) {
        if (x < 0 || x >= m_ || y < 0 || y >= n_ || visited[x][y]) {
            return;
        }
        if (grid[x][y] != origin_color) {
            return;
        }
        if (is_border(grid, x, y)) {
            to_color.emplace_back(x, y);
        }
        visited[x][y] = true;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            dfs(grid, visited, to_color, nx, ny, origin_color);
        }
    }

   private:
    int m_;
    int n_;

   public:
    vector<vector<int>> colorBorder(vector<vector<int>> &grid, int row, int col,
                                    int color) {
        if (grid.empty()) return {};
        m_ = grid.size();
        n_ = grid[0].size();
        vector<vector<int>> visited(m_, vector<int>(n_, false));
        vector<tuple<int, int>> to_color;
        dfs(grid, visited, to_color, row, col, grid[row][col]);

        for (auto [x, y] : to_color) {
            grid[x][y] = color;
        }
        return grid;
    }
};