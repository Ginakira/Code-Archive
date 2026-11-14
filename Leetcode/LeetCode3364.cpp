// LeetCode 3364 最小正和子数组

class Solution {
 public:
  int minimumSumSubarray(vector<int>& nums, int l, int r) {
    int n = nums.size();
    vector<int> presum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
      presum[i + 1] = presum[i] + nums[i];
    }

    int ans = numeric_limits<int>::max();
    for (int len = l; len <= r; ++len) {
      for (int i = len; i <= n; ++i) {
        if (int sum = presum[i] - presum[i - len]; sum > 0) {
          ans = min(ans, sum);
        }
      }
    }
    return ans == numeric_limits<int>::max() ? -1 : ans;
  }
};