// LeetCode 3350 检测相邻递增子数组 II

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
  int maxIncreasingSubarrays(vector<int>& nums) {
    int ans = 0;
    int n = nums.size(), pre_cnt = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
      ++cnt;
      if (i == n - 1 || nums[i] >= nums[i + 1]) {
        ans = max({ans, cnt / 2, min(cnt, pre_cnt)});
        pre_cnt = cnt;
        cnt = 0;
      }
    }
    return ans;
  }
};