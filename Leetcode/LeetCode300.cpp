// 每日一题 最长上升子序列
#include <vector>
using namespace std;

// 解法1:动态规划 dp[i]代表前i个数字的最长上升子序列 52ms
// 如果nums[i]之前的nums[j]比其小，则证明nums[i]可以接在nums[j]后面
class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (!n) return 0;
        int dp[n];
        fill(dp, dp + n, 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        int ans = -1;
        for (int i = 0; i < n; ++i) ans = max(ans, dp[i]);
        return ans;
    }
};