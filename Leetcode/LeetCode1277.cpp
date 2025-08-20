// LeetCode 1277 统计全为 1 的正方形子矩阵

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
  int countSquares(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> f(n + 1, vector<int>(m + 1));
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (matrix[i][j]) {
          f[i + 1][j + 1] = min({f[i][j], f[i + 1][j], f[i][j + 1]}) + 1;
          ans += f[i + 1][j + 1];
        }
      }
    }
    return ans;
  }
};