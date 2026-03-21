// LeetCode 3643 垂直翻转子矩阵

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
  vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y,
                                       int k) {
    int n = grid.size(), m = grid[0].size();
    for (int i = 0; i < k / 2; ++i) {
      for (int j = y; j < y + k; ++j) {
        std::swap(grid[x + i][j], grid[x + k - i - 1][j]);
      }
    }
    return grid;
  }
};