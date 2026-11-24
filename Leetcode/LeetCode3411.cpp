// LeetCode 3411 最长乘积等价子数组

class Solution {
 public:
  int maxLength(vector<int>& nums) {
    int ans = 0;
    for (int i = 0; i < nums.size(); ++i) {
      long long prod_val = nums[i];
      long long gcd_val = nums[i];
      long long lcm_val = nums[i];
      for (int j = i + 1; j < nums.size(); ++j) {
        prod_val = prod_val * nums[j];
        gcd_val = gcd(gcd_val, nums[j]);
        lcm_val = lcm(lcm_val, nums[j]);
        if (prod_val > gcd_val * lcm_val) {
          break;
        }
        if (prod_val == gcd_val * lcm_val) {
          ans = max(ans, j - i + 1);
        }
      }
    }
    return ans;
  }
};