// LeetCode 1219 黄金矿工

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   private:
    int max_ans = 0;
    int dirs[4][2]{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<int>> vis;
    int m;
    int n;

    void dfs(int i, int j, int cur, vector<vector<int>> &grid) {
        if (i < 0 || i >= n || j < 0 || j >= m || vis[i][j] ||
            grid[i][j] == 0) {
            return;
        }
        vis[i][j] = true;
        cur += grid[i][j];
        max_ans = max(max_ans, cur);
        for (auto &dir : dirs) {
            dfs(i + dir[0], j + dir[1], cur, grid);
        }
        vis[i][j] = false;
    }

   public:
    int getMaximumGold(vector<vector<int>> &grid) {
        n = grid.size();
        m = grid[0].size();
        vis.resize(n, vector<int>(m));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                dfs(i, j, 0, grid);
            }
        }

        return max_ans;
    }
};