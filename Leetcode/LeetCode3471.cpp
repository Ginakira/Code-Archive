// LeetCode 3471 找出最大的几近缺失整数

class Solution {
 public:
  int largestInteger(vector<int>& nums, int k) {
    map<int, int, std::greater<int>> cnt;
    for (int i = 0; i <= nums.size() - k; ++i) {
      unordered_set<int> us(nums.begin() + i, nums.begin() + i + k);
      for (int num : us) {
        ++cnt[num];
      }
    }
    int ans = -1;
    for (auto [num, c] : cnt) {
      if (c == 1) {
        ans = num;
        break;
      }
    }
    return ans;
  }
};