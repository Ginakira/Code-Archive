// LeetCode 377 组合总和IV
#include <limits>
#include <vector>
using namespace std;

// dp[i] 代表当目标为i时的方案总数，初始状态dp[0]=1
class Solution {
   public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1);
        dp[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (int num : nums) {
                if (num <= i &&
                    dp[i - num] < std::numeric_limits<int>::max() - dp[i]) {
                    dp[i] += dp[i - num];
                }
            }
        }
        return dp[target];
    }
};