// LeetCode 1049 最后一块石头的重量II
#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 01背包问题
// 问题可以转化为将石头加上正号或负号，求最终整个表达式的最小的绝对值，也就是转化成在石头中取不超过sum/2的最大值，代价和价值是石头本身
// dp[i][j]代表取前i个石头最大重量为j时能取到的最大重量
class Solution {
   public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size(),
            sum = accumulate(stones.begin(), stones.end(), 0);
        int target = sum / 2;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1));
        for (int i = 1; i <= n; ++i) {
            int stone = stones[i - 1];
            for (int j = 0; j <= target; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (j >= stone) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - stone] + stone);
                }
            }
        }
        return abs(dp[n][target] - (sum - dp[n][target]));
    }
};