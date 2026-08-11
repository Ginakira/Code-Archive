// LeetCode 2996 大于等于顺序前缀和的最小缺失整数

class Solution {
 public:
  int missingInteger(vector<int>& nums) {
    int sum = nums[0];
    for (int i = 1; i < nums.size() && nums[i] == nums[i - 1] + 1; ++i) {
      sum += nums[i];
    }

    unordered_set<int> s(nums.begin(), nums.end());
    while (s.contains(sum)) {
      ++sum;
    }
    return sum;
  }
};