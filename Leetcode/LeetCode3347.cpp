// LeetCode 3347 执行操作后元素的最高频率 II

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
  int maxFrequency(vector<int>& nums, int k, int numOperations) {
    unordered_map<int, int> cnt;
    map<int, int> diff;
    for (int num : nums) {
      ++cnt[num];
      diff[num];
      ++diff[num - k];
      --diff[num + k + 1];
    }
    int ans = 0, sum_d = 0;
    for (auto& [x, d] : diff) {
      sum_d += d;
      ans = max(ans, min(sum_d, numOperations + cnt[x]));
    }
    return ans;
  }
};