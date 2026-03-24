// LeetCode 2906 构造乘积矩阵

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
  vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
    constexpr int MOD = 12345;
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> ans(n, vector<int>(m));

    long long suf_prod = 1;
    for (int i = n - 1; i >= 0; --i) {
      for (int j = m - 1; j >= 0; --j) {
        ans[i][j] = suf_prod;
        suf_prod = suf_prod * grid[i][j] % MOD;
      }
    }

    long long pre_prod = 1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        ans[i][j] = ans[i][j] * pre_prod % MOD;
        pre_prod = pre_prod * grid[i][j] % MOD;
      }
    }
    return ans;
  }
};