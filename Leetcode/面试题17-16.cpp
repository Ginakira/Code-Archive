// 每日一题 按摩师
#include <vector>
using namespace std;

// 经典dp 代表到第i个客人为止的最大服务时间
// 第i个人两种选择：接，则为这个人时间+前天最大时间
// 不接，则为昨天最大时间，取二者较大值即可

class Solution {
   public:
    int massage(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int dp[n + 5];
        dp[0] = nums[0], dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; ++i) {
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }
        return dp[n - 1];
    }
};