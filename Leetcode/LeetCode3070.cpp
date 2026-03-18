// LeetCode 3070 元素和小于等于 k 的子矩阵的数目

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
  int countSubmatrices(vector<vector<int>>& grid, int k) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> sum(n + 1, vector<int>(m + 1, 0));
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        sum[i][j] = grid[i - 1][j - 1] + sum[i][j - 1] + sum[i - 1][j] -
                    sum[i - 1][j - 1];
        if (sum[i][j] <= k) {
          ++cnt;
        }
      }
    }
    return cnt;
  }
};

class Solution2 {
 public:
  int countSubmatrices(vector<vector<int>>& grid, int k) {
    int n = grid.size(), m = grid[0].size();
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (j > 0) {
          grid[i][j] += grid[i][j - 1];
        }
        if (i > 0) {
          grid[i][j] += grid[i - 1][j];
        }
        if (i > 0 && j > 0) {
          grid[i][j] -= grid[i - 1][j - 1];
        }
        if (grid[i][j] > k) {
          break;
        }
        ++cnt;
      }
    }
    return cnt;
  }
};