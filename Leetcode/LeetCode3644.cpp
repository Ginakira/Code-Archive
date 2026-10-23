// LeetCode 3644 排序排列

class Solution {
 public:
  int sortPermutation(vector<int>& nums) {
    int ans = -1;
    for (int i = 0; i < nums.size(); ++i) {
      if (i != nums[i]) {
        ans &= nums[i];
      }
    }
    return max(0, ans);
  }
};