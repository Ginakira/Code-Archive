// LeetCode 3731 找出缺失的元素
#include <ranges>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> findMissingElements(vector<int>& nums) {
    ranges::sort(nums);
    if (nums.back() - nums[0] == nums.size() - 1) {
      return {};
    }
    vector<int> ans;
    ans.reserve(nums.back() - nums[0] - nums.size());
    for (int cur = nums[0]; int num : nums) {
      while (cur < num) {
        ans.emplace_back(cur);
        ++cur;
      }
      ++cur;
    }
    return ans;
  }
};