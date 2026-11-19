// LeetCode 2567 修改两个元素的最小分数

class Solution {
 public:
  int minimizeSum(vector<int>& nums) {
    ranges::sort(nums);
    int n = nums.size();
    return min(
        {nums[n - 3] - nums[0], nums[n - 2] - nums[1], nums[n - 1] - nums[2]});
  }
};