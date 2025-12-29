// LeetCode 756 金字塔转换矩阵

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
  bool pyramidTransition(string bottom, vector<string>& allowed) {
    string groups[6][6]{};
    for (const auto& s : allowed) {
      groups[s[0] - 'A'][s[1] - 'A'] += s[2];
    }
    int n = bottom.size();
    vector<string> grid(n);
    for (int i = 0; i < n - 1; ++i) {
      grid[i].resize(i + 1);
    }
    grid[n - 1] = std::move(bottom);

    auto dfs = [&](this auto&& dfs, int i, int j) -> bool {
      if (i < 0) {
        return true;
      }
      if (j == i + 1) {
        return dfs(i - 1, 0);
      }

      for (char top : groups[grid[i + 1][j] - 'A'][grid[i + 1][j + 1] - 'A']) {
        grid[i][j] = top;
        if (dfs(i, j + 1)) {
          return true;
        }
      }
      return false;
    };
    return dfs(n - 2, 0);
  }
};