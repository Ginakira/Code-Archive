// LeetCode 1351 统计有序矩阵中的负数

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
  int countNegatives(vector<vector<int>>& grid) {
    int ans = 0;
    int m = grid[0].size();
    for (const auto& row : grid) {
      auto it = lower_bound(row.rbegin(), row.rend(), 0);
      if (it != row.rend()) {
        ans += distance(row.rbegin(), it);
      } else {
        ans += m;
      }
    }
    return ans;
  }
};