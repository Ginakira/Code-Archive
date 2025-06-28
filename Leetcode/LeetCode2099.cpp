// LeetCode 2099 找到和最大的长度为 K 的子序列

#include <algorithm>
#include <array>
#include <numeric>
#include <queue>
#include <ranges>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> maxSubsequence(vector<int>& nums, int k) {
    auto idxs = views::iota(0zu, nums.size()) | ranges::to<vector<int>>();
    auto f = [&](auto i) { return nums[i]; };
    ranges::nth_element(idxs, idxs.begin() + k, greater{}, f);
    ranges::sort(idxs | views::take(k));
    return idxs | views::take(k) | views::transform(f) | ranges::to<vector>();
  }
};