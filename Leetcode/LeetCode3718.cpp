// LeetCode 3718 缺失的最小倍数

class Solution {
 public:
  int missingMultiple(vector<int>& nums, int k) {
    unordered_set<int> mark(nums.begin(), nums.end());
    int cur = k;
    while (true) {
      if (mark.contains(cur)) {
        cur += k;
        continue;
      }
      break;
    }
    return cur;
  }
};