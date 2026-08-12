// LeetCode 2958 最多 K 个重复元素的最长子数组

class Solution {
 public:
  int maxSubarrayLength(vector<int>& nums, int k) {
    unordered_map<int, int> cnt;
    int ans = 0;
    for (int l = 0, r = 0; r < nums.size(); ++r) {
      ++cnt[nums[r]];
      while (cnt[nums[r]] > k && l < r) {
        --cnt[nums[l]];
        ++l;
      }
      ans = max(ans, r - l + 1);
    }
    return ans;
  }
};