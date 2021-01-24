// LeetCode 674 最长连续递增序列
#include <vector>
using namespace std;

// 双指针法
class Solution {
   public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int left = 0, right = 0, ans = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] <= nums[i - 1]) {
                ans = max(ans, right - left + 1);
                left = right = i;
            } else {
                right = i;
            }
        }
        ans = max(ans, right - left + 1);
        return ans;
    }
};