// LeetCode 198 打家劫舍
#include <vector>
using namespace std;

// Solution1:递归 + 滚动数组
// 状态转移方程：dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
class Solution {
   public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        int ppre = nums[0], pre = max(nums[0], nums[1]);
        int ans = max(pre, ppre);
        for (int i = 2; i < nums.size(); ++i) {
            int temp = max(ppre + nums[i], pre);
            ans = max(ans, temp);
            ppre = pre, pre = temp;
        }
        return ans;
    }
};

class Solution2 {
   public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, pre = 0, ppre = 0;
        pre = nums[0], ans = pre;
        for (int i = 1; i < n; ++i) {
            ans = max(nums[i] + ppre, pre);
            ppre = pre, pre = ans;
        }
        return ans;
    }
};