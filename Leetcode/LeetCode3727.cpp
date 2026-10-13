// LeetCode 3727 最大交替平方和

class Solution {
 public:
  long long maxAlternatingSum(vector<int>& nums) {
    ranges::sort(nums, [](int a, int b) { return abs(a) > abs(b); });
    int n = nums.size();
    long long ans = 0;
    for (int i = 0; i < (n + 1) / 2; ++i) {
      ans += 1LL * nums[i] * nums[i];
      if (i != n / 2) {
        ans -= 1LL * nums[n - i - 1] * nums[n - i - 1];
      }
    }
    return ans;
  }
};