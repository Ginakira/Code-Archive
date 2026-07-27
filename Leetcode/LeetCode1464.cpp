// LeetCode 1464 数组中两元素的最大乘积

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    sort(nums.begin(), nums.end(), greater<int>());
    return (nums[0] - 1) * (nums[1] - 1);
  }
};

class Solution2 {
 public:
  int maxProduct(vector<int>& nums) {
    int n = nums.size();
    ranges::sort(nums);
    return (nums[n - 1] - 1) * (nums[n - 2] - 1);
  }
};