// LeetCode 228 汇总区间
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        for (int i = 0, n = nums.size(), pre = 0; i < n; ++i) {
            if (i == n - 1 || nums[i] + 1 != nums[i + 1]) {
                ret.push_back(i == pre ? to_string(nums[i])
                                       : to_string(nums[pre]) + "->" +
                                             to_string(nums[i]));
                pre = i + 1;
            }
        }
        return ret;
    }
};