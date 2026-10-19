// LeetCode 2089 找出数组排序后的目标下标

class Solution {
 public:
  vector<int> targetIndices(vector<int>& nums, int target) {
    ranges::sort(nums);
    vector<int> ans;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == target) {
        ans.emplace_back(i);
      }
    }
    return ans;
  }
};