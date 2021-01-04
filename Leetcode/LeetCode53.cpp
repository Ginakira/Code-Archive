// LeetCode 53 最大子序和
#include <vector>
using namespace std;

// Solution1：动态规划，使用滚动数组优化
// 状态转移方程：dp[i] = max(dp[i - 1] + num[i], num[i]);
// 取最大值即可
class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0, ans = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            pre = max(pre + nums[i], nums[i]);
            ans = max(ans, pre);
        }
        return ans;
    }
};