// LeetCode 714 买卖股票的最佳时机含手续费
#include <vector>
using namespace std;

// Solution 1 动态规划
// dp[i][0]代表第i天不持有股票时的最大收益
// 则可以从i - 1天不持有或i - 1天持有第i天卖出转移过来
// dp[i][1]代表第i天持有股票时的最大收益
// 则可以从i - 1天持有或i - 1天不持有第i天买入转移过来
class Solution {
   public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][0] = 0, dp[0][1] = -prices[0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[n - 1][0];
    }
};