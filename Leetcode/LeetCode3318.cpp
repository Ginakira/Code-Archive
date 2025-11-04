// LeetCode 3318 计算子数组的 x-sum I

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
  vector<int> findXSum(vector<int>& nums, int k, int x) {
    int n = nums.size();
    auto xsum = [&](int start, int end) {
      end = min(end, n - 1);
      unordered_map<int, int> cnt;
      for (int i = start; i <= end; ++i) {
        ++cnt[nums[i]];
      }
      vector<pair<int, int>> stats;
      for (const auto [k, v] : cnt) {
        stats.emplace_back(v, k);
      }
      ranges::sort(stats, std::greater());
      int sum = 0, m = min(static_cast<int>(stats.size()), x);
      for (int i = 0; i < min(m, x); ++i) {
        sum += stats[i].first * stats[i].second;
      }
      return sum;
    };
    vector<int> ans;
    for (int i = 0; i <= n - k; ++i) {
      ans.emplace_back(xsum(i, i + k - 1));
    }
    return ans;
  }
};