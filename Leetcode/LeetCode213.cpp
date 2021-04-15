// LeetCode 213 打家劫舍II
#include <vector>
using namespace std;

class Solution {
   public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        if (n == 1) return nums[0];
        // 1 to n-1
        int a_ans = nums[0], a_pre = nums[0], a_ppre = 0;
        for (int i = 1; i < n - 1; ++i) {
            a_ans = max(a_ppre + nums[i], a_pre);
            a_ppre = a_pre, a_pre = a_ans;
        }
        // 2 to n
        int b_ans = nums[1], b_pre = nums[1], b_ppre = 0;
        for (int i = 2; i < n; ++i) {
            b_ans = max(b_ppre + nums[i], b_pre);
            b_ppre = b_pre, b_pre = b_ans;
        }
        return max(a_ans, b_ans);
    }
};