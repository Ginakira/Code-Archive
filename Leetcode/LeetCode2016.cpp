// LeetCode 2016 增量元素之间的最大差值

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 暴力
class Solution {
public:
  int maximumDifference(vector<int> &nums) {
    int max_diff = 0;
    size_t n = nums.size();
    for (size_t i = 0; i < n; ++i) {
      for (size_t j = i + 1; j < n; ++j) {
        int diff = nums[j] - nums[i];
        if (diff > max_diff) {
          max_diff = diff;
        }
      }
    }
    return max_diff == 0 ? -1 : max_diff;
  }
};

// 最小前缀
class Solution2 {
public:
  int maximumDifference(vector<int> &nums) {
    int ans = -1, pre_min = nums[0];
    size_t n = nums.size();
    for (size_t i = 1; i < n; ++i) {
      if (nums[i] > pre_min) {
        ans = max(ans, nums[i] - pre_min);
      } else {
        pre_min = nums[i];
      }
    }
    return ans;
  }
};

class Solution3 {
public:
  int maximumDifference(vector<int> &nums) {
    int ans = -1;
    int min_val = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > min_val) {
        ans = max(ans, nums[i] - min_val);
      }
      min_val = min(min_val, nums[i]);
    }
    return ans;
  }
};