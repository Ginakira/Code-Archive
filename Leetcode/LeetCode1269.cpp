// LeetCode 1269 停在原地的方案数
#include <vector>
using namespace std;

class Solution {
   public:
    int numWays(int steps, int arrLen) {
        const int MOD = 1000000007;
        // 最多走steps / 2 + 1这么远，因为返回还需要steps / 2步
        int len = min(steps / 2 + 1, arrLen);
        // dp[i][j] 走 i 步后停留在坐标 j 上的方案数
        // dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]
        vector<vector<int>> dp(steps + 1, vector<int>(len));
        dp[0][0] = 1;
        for (int i = 1; i <= steps; ++i) {
            for (int j = 0; j < len; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (j > 0) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
                if (j < len - 1) dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
            }
        }
        return dp[steps][0];
    }
};