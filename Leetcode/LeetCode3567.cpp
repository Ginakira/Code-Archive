// LeetCode 3567 子矩阵的最小绝对差

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
  vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
    int n = grid.size() - k + 1, m = grid[0].size() - k + 1;
    vector<vector<int>> ans(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        vector<int> nums;
        nums.reserve(k * k);
        for (int p = 0; p < k; ++p) {
          for (int q = 0; q < k; ++q) {
            nums.push_back(grid[i + p][j + q]);
          }
        }
        ranges::sort(nums);
        int min_diff = numeric_limits<int>::max();
        for (int p = 1; p < k * k; ++p) {
          if (nums[p] > nums[p - 1]) {
            min_diff = min(min_diff, nums[p] - nums[p - 1]);
          }
        }
        if (min_diff < numeric_limits<int>::max()) {
          ans[i][j] = min_diff;
        }
      }
    }
    return ans;
  }
};