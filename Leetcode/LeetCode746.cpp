// LeetCode 746 使用最小花费爬楼梯
#include <vector>
using namespace std;

// 简单递推
class Solution {
   public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        std::vector<int> dp(n + 1, 0);
        for (int i = 2; i <= n; ++i) {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[n];
    }
};