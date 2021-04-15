// LeetCode 213 打家劫舍II
#include <vector>
using namespace std;

class Solution {
   public:
    int helper(vector<int>& nums, int start, int end) {
        int ans = nums[start], pre = nums[start], ppre = 0;
        for (int i = start + 1; i <= end; ++i) {
            ans = max(ppre + nums[i], pre);
            ppre = pre, pre = ans;
        }
        return ans;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        return max(helper(nums, 0, n - 2), helper(nums, 1, n - 1));
    }
};