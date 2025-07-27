// LeetCode 2210 统计数组中峰和谷的数量

#include <algorithm>
#include <array>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int countHillValley(vector<int>& nums) {
    int ans = 0;
    int n = nums.size();
    int i = 1;
    while (nums[i] == nums[0]) {
      ++i;
    }
    while (i < n - 1) {
      int l = nums[i - 1];
      int j = i + 1;
      while (j < n && nums[i] == nums[j]) {
        ++j;
      }
      if (j < n) {
        int r = nums[j];
        if ((l < nums[i] && nums[i] > r) || (l > nums[i] && nums[i] < r)) {
          ++ans;
        }
      }
      i = j;
    }
    return ans;
  }
};