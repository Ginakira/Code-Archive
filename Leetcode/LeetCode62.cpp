// LeetCode 62 不同路径

#include <vector>
using namespace std;

// Solution1: 经典动规 与「走楼梯」思路一致
// 状态转移方程：f[i][j] = f[i - 1][j] + f[i][j - 1]
class Solution {
   public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            dp[i][0] = 1;
        }
        for (int j = 0; j < m; ++j) {
            dp[0][j] = 1;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[n - 1][m - 1];
    }
};