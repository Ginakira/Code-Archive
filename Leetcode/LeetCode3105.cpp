// LeetCode 3105 最长的严格递增或递减子数组

class Solution {
 public:
  int longestMonotonicSubarray(vector<int>& nums) {
    int max_len = 1;
    int n = nums.size();
    nums.emplace_back(0);
    for (int l = 0, r = 0; r <= n; ++r) {
      if (r > 0 && nums[r] <= nums[r - 1]) {
        max_len = max(max_len, r - l);
        l = r;
      }
    }
    nums.back() = 100;
    for (int l = 0, r = 0; r <= n; ++r) {
      if (r > 0 && nums[r] >= nums[r - 1]) {
        max_len = max(max_len, r - l);
        l = r;
      }
    }
    return max_len;
  }
};