// LeetCode 3583 统计特殊三元组

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
  int specialTriplets(vector<int>& nums) {
    long long ans = 0;
    int n = nums.size();
    static constexpr int MOD = 1e9 + 7;
    unordered_map<int, vector<int>> num_to_idxs;
    for (int i = 0; i < n; ++i) {
      num_to_idxs[nums[i]].emplace_back(i);
    }
    for (int i = 0; i < n; ++i) {
      int target = nums[i] * 2;
      auto idxs_it = num_to_idxs.find(target);
      if (idxs_it == num_to_idxs.end()) {
        continue;
      }
      const auto& idxs = idxs_it->second;
      auto right_it = ranges::upper_bound(idxs, i);
      int right = distance(right_it, idxs.end());
      int left = idxs.size() - right;
      if (target == nums[i]) {
        --left;
      }
      ans = (ans + 1LL * left * right) % MOD;
    }
    return ans;
  }
};