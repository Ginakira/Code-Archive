// LeetCode 3904 最小稳定下标 II

class Solution {
 public:
  int firstStableIndex(vector<int>& nums, int k) {
    stack<int> min_stk;
    int cur_max = 0;
    int n = nums.size();
    for (int i = n - 1; i >= 0; --i) {
      if (min_stk.empty() || nums[i] <= nums[min_stk.top()]) {
        min_stk.emplace(i);
      }
    }
    for (int i = 0; i < n; ++i) {
      cur_max = max(cur_max, nums[i]);
      while (!min_stk.empty() && min_stk.top() < i) {
        min_stk.pop();
      }
      if (!min_stk.empty() && cur_max - nums[min_stk.top()] <= k) {
        return i;
      }
    }
    return -1;
  }
};
