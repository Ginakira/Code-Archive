// LeetCode 2257 统计网格图中没有被保卫的格子数

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
  int countUnguarded(int m, int n, vector<vector<int>>& guards,
                     vector<vector<int>>& walls) {
    vector<vector<int>> grid(m, vector<int>(n, 0));
    int ans = m * n;
    for (const auto& g : guards) {
      grid[g[0]][g[1]] = -1;
      --ans;
    }
    for (const auto& w : walls) {
      grid[w[0]][w[1]] = -1;
      --ans;
    }
    for (const auto& g : guards) {
      int gi = g[0], gj = g[1];
      static constexpr std::array<std::array<int, 2>, 4> dirs{
          {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}};
      for (auto& [dx, dy] : dirs) {
        int x = gi + dx, y = gj + dy;
        while (x >= 0 && x < m && y >= 0 && y < n) {
          if (grid[x][y] == -1) {
            break;
          } else if (grid[x][y] == 0) {
            grid[x][y] = 1;
            --ans;
          }
          x += dx, y += dy;
        }
      }
    }
    return ans;
  }
};