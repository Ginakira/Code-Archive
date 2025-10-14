// LeetCode 3349 检测相邻递增子数组I

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
  bool hasIncreasingSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    for (int i = 0, pre_cnt = 0, cnt = 0; i < n; ++i) {
      ++cnt;
      if (i == nums.size() - 1 || nums[i] >= nums[i + 1]) {
        if (max(cnt / 2, min(pre_cnt, cnt)) >= k) {
          return true;
        }
        pre_cnt = cnt;
        cnt = 0;
      }
    }
    return false;
  }
};