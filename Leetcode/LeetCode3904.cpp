// LeetCode 3904 最小稳定下标 II

class Solution {
 public:
  int firstStableIndex(vector<int>& nums, int k) {
    int cur_max = 0, cur_min = nums.back();
    int n = nums.size();
    vector<int> min_val(n);
    min_val[n - 1] = cur_min;
    for (int i = n - 2; i >= 0; --i) {
      min_val[i] = min(nums[i], min_val[i + 1]);
    }
    for (int i = 0; i < n; ++i) {
      cur_max = max(cur_max, nums[i]);
      if (cur_max - min_val[i] <= k) {
        return i;
      }
    }
    return -1;
  }
};