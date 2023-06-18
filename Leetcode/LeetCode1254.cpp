// LeetCode 1254 统计封闭岛屿的数目

#include <algorithm>
#include <array>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   private:
    void dfs(vector<vector<int>>& grid, int x, int y) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() ||
            grid[x][y]) {
            return;
        }
        grid[x][y] = 1;
        dfs(grid, x - 1, y);
        dfs(grid, x + 1, y);
        dfs(grid, x, y - 1);
        dfs(grid, x, y + 1);
    }

   public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if (n < 3 || m < 3) {
            return 0;
        }
        for (int i = 0; i < n; ++i) {
            // 如果是第一行和最后一行，访问所有格子
            // 如果不是，只访问第一列和最后一列的格子
            int step = i == 0 || i == n - 1 ? 1 : m - 1;
            for (int j = 0; j < m; j += step) {
                dfs(grid, i, j);
            }
        }

        int ans = 0;
        for (int i = 1; i < n - 1; ++i) {
            for (int j = 1; j < m - 1; ++j) {
                if (grid[i][j] == 0) {
                    ++ans;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }
};