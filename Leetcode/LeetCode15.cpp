// LeetCode 15 三数之和
#include <algorithm>
#include <vector>
using namespace std;

// 排序后使用双指针
class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        for (int first = 0; first < n; ++first) {
            if (first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }
            int target = -nums[first];
            int third = n - 1;
            for (int second = first + 1; second < n; ++second) {
                if (second > first + 1 && nums[second] == nums[second - 1]) {
                    continue;
                }
                while (second < third && nums[third] + nums[second] > target) {
                    --third;
                }
                if (second == third) {
                    break;
                }
                if (nums[second] + nums[third] == target) {
                    ret.push_back({nums[first], nums[second], nums[third]});
                }
            }
        }
        return ret;
    }
};