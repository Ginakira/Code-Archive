// LeetCode 53 最大子序和
#include <vector>
using namespace std;

// Solution1：动态规划，使用滚动数组优化
// 状态转移方程：dp[i] = max(dp[i - 1] + num[i], num[i]);
// 取最大值即可
class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, max_ans = INT_MIN;
        for (const int& num : nums) {
            sum = max(sum + num, num);
            max_ans = max(sum, max_ans);
        }
        return max_ans;
    }
};