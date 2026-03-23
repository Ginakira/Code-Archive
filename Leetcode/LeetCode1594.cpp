// LeetCode 1594 矩阵的最大非负积

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
  int maxProductPath(vector<vector<int>>& grid) {
    using LL = long long;
    constexpr int MOD = 1e9 + 7;
    int n = grid.size(), m = grid[0].size();
    vector<vector<LL>> max_prod(n, vector<LL>(m));
    vector<vector<LL>> min_prod(n, vector<LL>(m));
    max_prod[0][0] = min_prod[0][0] = grid[0][0];
    for (int j = 1; j < m; ++j) {
      max_prod[0][j] = min_prod[0][j] = max_prod[0][j - 1] * grid[0][j];
    }
    for (int i = 1; i < n; ++i) {
      max_prod[i][0] = min_prod[i][0] = max_prod[i - 1][0] * grid[i][0];
    }
    for (int i = 1; i < n; ++i) {
      for (int j = 1; j < m; ++j) {
        if (grid[i][j] >= 0) {
          max_prod[i][j] =
              max(max_prod[i][j - 1], max_prod[i - 1][j]) * grid[i][j];
          min_prod[i][j] =
              min(min_prod[i][j - 1], min_prod[i - 1][j]) * grid[i][j];
        } else {
          max_prod[i][j] =
              min(min_prod[i][j - 1], min_prod[i - 1][j]) * grid[i][j];
          min_prod[i][j] =
              max(max_prod[i][j - 1], max_prod[i - 1][j]) * grid[i][j];
        }
      }
    }
    if (max_prod[n - 1][m - 1] < 0) {
      return -1;
    }
    return max_prod[n - 1][m - 1] < 0 ? -1 : max_prod[n - 1][m - 1] % MOD;
  }
};