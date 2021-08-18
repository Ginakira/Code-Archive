// 剑指 Offer 47. 礼物的最大价值
#include <vector>
using namespace std;

// DP
class Solution {
   public:
    int maxValue(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
            }
        }
        return dp[n][m];
    }
};

// DFS 超时
class Solution2 {
   private:
    vector<vector<int>> visited;
    vector<vector<int>> dir = {{0, 1}, {1, 0}};
    int n, m;
    int max_value = 0;

    inline bool is_valid_coordinate(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    void dfs(int x, int y, int value, vector<vector<int>>& grid) {
        if (x == n - 1 && y == m - 1) {
            max_value = max(max_value, value);
            return;
        }
        visited[x][y] = 1;
        for (int i = 0; i < dir.size(); ++i) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (!is_valid_coordinate(nx, ny) || visited[nx][ny]) continue;
            dfs(nx, ny, value + grid[nx][ny], grid);
        }
        visited[x][y] = 0;
    }

   public:
    int maxValue(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        visited.resize(n, vector<int>(m, 0));
        dfs(0, 0, grid[0][0], grid);
        return max_value;
    }
};