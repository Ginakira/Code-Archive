// LeetCode 1260 二维网格迁移

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
    int n = grid.size(), m = grid[0].size(), item_n = n * m;
    k %= item_n;
    vector<vector<int>> result(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int target_id = (i * m + j + k) % item_n;
        result[target_id / m][target_id % m] = grid[i][j];
      }
    }
    return result;
  }
};

class Solution2 {
 public:
  vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
    int n = grid.size(), m = grid[0].size();
    k %= n * m;
    vector<vector<int>> ans(n, vector<int>(m));
    int ai = k / m, aj = k % m;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        ans[ai][aj] = grid[i][j];
        if (++aj == m) {
          ++ai;
          aj = 0;
        }
        if (ai == n) {
          ai = 0;
        }
      }
    }
    return ans;
  }
};