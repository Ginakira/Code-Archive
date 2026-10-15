// LeetCode 2913 子数组不同元素数目的平方和 I

class Solution {
 public:
  int sumCounts(vector<int>& nums) {
    int n = nums.size(), res = 0;
    for (int i = 0; i < n; i++) {
      unordered_set<int> s;
      for (int j = i; j < n; j++) {
        s.insert(nums[j]);
        res += s.size() * s.size();
      }
    }
    return res;
  }
};