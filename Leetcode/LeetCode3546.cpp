// LeetCode 3546 等和矩阵分割 I

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
  bool canPartitionGrid(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<long long>> sum(n + 1, vector<long long>(m + 1));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        sum[i + 1][j + 1] =
            sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + grid[i][j];
      }
    }

    long long total = sum.back().back();
    if (total & 1) {
      return false;
    }
    for (int i = 1; i <= n; ++i) {
      if (sum[i][m] * 2 == total) {
        return true;
      }
    }
    for (int j = 1; j <= m; ++j) {
      if (sum[n][j] * 2 == total) {
        return true;
      }
    }
    return false;
  }
};
