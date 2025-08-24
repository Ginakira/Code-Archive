// LeetCode 1493 删掉一个元素以后全为 1 的最长子数组

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
  int longestSubarray(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    int zero_cnt = 0;
    for (int l = 0, r = 0; r < n; ++r) {
      zero_cnt += nums[r] == 0;
      while (zero_cnt > 1 && l < r) {
        zero_cnt -= nums[l++] == 0;
      }
      ans = max(ans, r - l);
    }
    return ans;
  }
};