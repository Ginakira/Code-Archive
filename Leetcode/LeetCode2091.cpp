// LeetCode 2091 从数组中移除最大值和最小值

class Solution {
 public:
  int minimumDeletions(vector<int>& nums) {
    int n = nums.size();
    int idx_a = ranges::min_element(nums) - nums.begin();
    int idx_b = ranges::max_element(nums) - nums.begin();
    if (idx_a < idx_b) {
      swap(idx_a, idx_b);
    }
    return min({idx_a + 1, n - idx_b, idx_b + 1 + n - idx_a});
  }
};