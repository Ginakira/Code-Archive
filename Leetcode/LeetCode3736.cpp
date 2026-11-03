// LeetCode 3736 最小操作次数使数组元素相等 III

class Solution {
 public:
  int minMoves(vector<int>& nums) {
    return *ranges::max_element(nums) * nums.size() -
           reduce(nums.begin(), nums.end(), 0);
  }
};