// LeetCode 1658 将X减到0的最小操作数

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int minOperations(vector<int>& nums, int x) {
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum < x) {
      return -1;
    }

    int right = 0;
    int left_sum = 0, right_sum = sum;
    int ans = n + 1;

    for (int left = -1; left < n; ++left) {
      if (left != -1) {
        left_sum += nums[left];
      }
      while (right < n && left_sum + right_sum > x) {
        right_sum -= nums[right];
        ++right;
      }
      if (left_sum + right_sum == x) {
        ans = min(ans, left + 1 + n - right);
      }
    }
    return ans > n ? -1 : ans;
  }
};

class Solution2 {
 public:
  int minOperations(vector<int>& nums, int x) {
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int target = sum - x;
    if (target == 0) {
      return n;
    }
    int ans = -1;
    for (int l = 0, r = 0, sum = 0; r < n; ++r) {
      sum += nums[r];
      while (sum > target && l < r) {
        sum -= nums[l++];
      }
      if (sum == target) {
        ans = max(ans, r - l + 1);
      }
    }
    return ans == -1 ? -1 : n - ans;
  }
};