// LeetCode 3195 包含所有 1 的最小矩形面积 I

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
  int minimumArea(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    int min_i = n, max_i = 0;
    int min_j = m, max_j = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j]) {
          min_i = min(min_i, i);
          max_i = max(max_i, i);
          min_j = min(min_j, j);
          max_j = max(max_j, j);
        }
      }
    }
    return (max_i - min_i + 1) * (max_j - min_j + 1);
  }
};