// LeetCode 3740 三个相等元素之间的最小距离 I

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
  int minimumDistance(vector<int>& nums) {
    unordered_map<int, vector<int>> idxs;
    int ans = numeric_limits<int>::max();
    for (int i = 0; i < nums.size(); ++i) {
      auto& v = idxs[nums[i]];
      v.emplace_back(i);
      if (v.size() >= 3) {
        ans = min(ans, 2 * v.back() - 2 * v[v.size() - 3]);
      }
    }
    return ans == numeric_limits<int>::max() ? -1 : ans;
  }
};