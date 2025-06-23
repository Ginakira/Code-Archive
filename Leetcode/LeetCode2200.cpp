// LeetCode 2200 - Find All K-Distant Indices in an Array

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
  vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
    vector<int> targets;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      if (nums[i] == key) {
        targets.emplace_back(i);
      }
    }
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
      int low = max(i - k, 0);
      int high = min(i + k, n - 1);
      auto l_it = ranges::lower_bound(targets, low);
      auto r_it = ranges::upper_bound(targets, high);
      if (l_it < r_it) {
        ans.emplace_back(i);
      }
    }
    return ans;
  }
};