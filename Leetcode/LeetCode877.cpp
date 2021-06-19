// LeetCode 877 石子游戏

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 动态规划 区间DP
// dp[i][j]代表[i,j]区间的石子中先手与后手分数的最大差值
class Solution {
   public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n + 2, vector<int>(n + 2));
        for (int len = 1; len <= n; ++len) {
            for (int l = 1; l + len - 1 <= n; ++l) {
                int r = l + len - 1;
                dp[l][r] = max(piles[l - 1] - dp[l + 1][r],
                               piles[r - 1] - dp[l][r - 1]);
            }
        }
        return dp[1][n] < 0 ? false : true;
    }
};