// LeetCode 628 三个数的最大乘积
#include <vector>
using namespace std;

class Solution {
 public:
  int maximumProduct(vector<int>& nums) {
    int n = nums.size();
    sort(nums.rbegin(), nums.rend());
    return max(nums[0] * nums[1] * nums[2],
               nums[0] * nums[n - 1] * nums[n - 2]);
  }
};

class Solution2 {
 public:
  int maximumProduct(vector<int>& nums) {
    int n = nums.size();
    ranges::sort(nums, greater<int>());
    return max(
        {nums[0] * nums[1] * nums[2], nums[0] * nums[n - 1] * nums[n - 2]});
  }
};