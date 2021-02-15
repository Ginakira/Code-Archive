// LeetCode 485 最大连续1的个数
#include <vector>
using namespace std;

class Solution {
   public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, l = 0, r = 0;
        while (r < n) {
            if (!nums[r]) {
                ans = max(ans, r - l);
                l = r + 1;
            }
            ++r;
        }
        return max(ans, r - l);
    }
};