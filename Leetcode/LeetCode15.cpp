// LeetCode 15 三数之和
#include <algorithm>
#include <vector>
using namespace std;

// 排序后使用双指针 固定第一位 转化为对第一位的两数之和
class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int first = 0; first < n; ++first) {
            if (first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }
            if (nums[first] > 0) continue;

            int second = first + 1, third = n - 1;
            int target = -nums[first];
            while (second < third) {
                int sum = nums[second] + nums[third];
                if (sum < target) {
                    ++second;
                } else if (sum > target) {
                    --third;
                } else {
                    ans.emplace_back(
                        vector<int>{nums[first], nums[second], nums[third]});
                    ++second, --third;
                    while (second < third && nums[second] == nums[second - 1])
                        ++second;
                    while (second < third && nums[third] == nums[third + 1])
                        --third;
                }
            }
        }
        return ans;
    }
};