// LeetCode 1878 矩阵中最大的菱形和

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
  vector<int> getBiggestThree(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    int max_k = (min(n, m) + 1) / 2;
    set<int, greater<int>> st;

    auto cal_rhombus = [&](int x, int y, int k) {
      if (k == 1) {
        return grid[x][y];
      }
      // k = 4
      // (-3, 0) (-2, -1) (-1, -2) (0, -3)
      // (3, 0) (2, 1) (1, 2) (0, 3)
      // (3, 0) (2, -1) (1, -2) (0, 3)
      // (-3, 0) (-2, 1) (-1, 2) (0, -3)
      array<array<int, 2>, 4> signs{{{-1, -1}, {1, 1}, {1, -1}, {-1, 1}}};
      int sum = 0;
      for (int i = 0; i < k; ++i) {
        int dx = k - i - 1, dy = i;
        for (auto [sx, sy] : signs) {
          int xx = x + dx * sx, yy = y + dy * sy;
          if (xx < 0 || xx >= n || yy < 0 || yy >= m) {
            return 0;
          }
          sum += grid[xx][yy];
        }
      }
      sum -= grid[x - k + 1][y] + grid[x + k - 1][y] + grid[x][y - k + 1] +
             grid[x][y + k - 1];
      return sum;
    };

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        for (int k = 1; k <= max_k; ++k) {
          int sum = cal_rhombus(i, j, k);
          st.emplace(sum);
        }
      }
    }
    size_t steps = min(st.size(), (size_t)3);
    return vector<int>(st.begin(), next(st.begin(), steps));
  }
};