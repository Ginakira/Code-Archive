// LeetCode 1292 元素和小于等于阈值的正方形的最大边长

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
  int maxSideLength(vector<vector<int>>& mat, int threshold) {
    int n = mat.size(), m = mat[0].size();
    vector<vector<int>> sum(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        sum[i][j] = sum[i - 1][j] + sum[i][j - 1] + mat[i - 1][j - 1] -
                    sum[i - 1][j - 1];
      }
    }
    int ans = 0;
    auto check = [&](int x1, int y1, int x2, int y2) -> bool {
      return sum[x2 + 1][y2 + 1] - sum[x2 + 1][y1] - sum[x1][y2 + 1] +
                 sum[x1][y1] <=
             threshold;
    };

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        while (i + ans < n && j + ans < m && check(i, j, i + ans, j + ans)) {
          ++ans;
        }
      }
    }
    return ans;
  }
};