// LeetCode 576 出界的路径数

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// DFS
class Solution {
   private:
    int m;
    int n;
    const int dirs[4][2]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    static constexpr int MOD = 1e9 + 7;
    vector<vector<vector<int>>> mem;

    int dfs(int x, int y, int move_remain) {
        if (x < 0 || x >= m || y < 0 || y >= n) {
            return 1;
        }
        if (move_remain == 0) {
            return 0;
        }
        if (mem[x][y][move_remain] != -1) {
            return mem[x][y][move_remain];
        }
        int ans = 0;
        for (auto &dir : dirs) {
            ans += dfs(x + dir[0], y + dir[1], move_remain - 1);
            ans %= MOD;
        }
        mem[x][y][move_remain] = ans;
        return ans;
    }

   public:
    int findPaths(int _m, int _n, int maxMove, int startRow, int startColumn) {
        m = _m, n = _n;
        mem.resize(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return dfs(startRow, startColumn, maxMove);
    }
};

// DP
class Solution2 {
   private:
    const int dirs[4][2]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    static constexpr int MOD = 1e9 + 7;

   public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        // dp[i][j][k] 从(i,j)出发最多走k步出界的路径
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(maxMove + 1, 0)));
        auto add = [&](int x, int y) {
            for (int i = 1; i <= maxMove; ++i) {
                ++dp[x][y][i];
            }
        };
        // 初始化边界状态
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0) add(i, j);  // 边界只有一条路径
                if (j == 0) add(i, j);
                if (i == m - 1) add(i, j);  // 边角有两条路径
                if (j == n - 1) add(i, j);
            }
        }

        for (int step = 1; step <= maxMove; ++step) {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    for (auto &dir : dirs) {
                        int tx = i + dir[0], ty = j + dir[1];
                        if (tx < 0 || tx >= m || ty < 0 || ty >= n) continue;
                        dp[i][j][step] += dp[tx][ty][step - 1];
                        dp[i][j][step] %= MOD;
                    }
                }
            }
        }
        return dp[startRow][startColumn][maxMove];
    }
};