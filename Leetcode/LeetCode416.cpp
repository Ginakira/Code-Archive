// LeetCode 416 分割等和子集

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 动归 01背包
// dp[i][j] 下标[0,i]范围内是否存在和为j的子集
class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return false;
        }
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int max_num = *max_element(nums.begin(), nums.end());
        if (sum & 1) {
            return false;
        }
        int target = sum / 2;
        if (max_num > target) {
            return false;
        }
        vector<vector<bool>> dp(n, vector<bool>(target + 1));
        for (int i = 0; i < n; ++i) {
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= target; ++j) {
                int num = nums[i];
                if (num <= j) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - num];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n - 1][target];
    }
};