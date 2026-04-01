// LeetCode 3418 机器人可以获得的最大金币数

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
  int maximumAmount(vector<vector<int>>& coins) {
    int n = coins.size(), m = coins[0].size();
    constexpr int kMin = numeric_limits<int>::min();
    auto mem = vector(n, vector(m, array<int, 3>{kMin, kMin, kMin}));
    auto dfs = [&](this auto&& dfs, int i, int j, int k) -> int {
      if (i >= n || j >= m) {
        return kMin;
      }
      int x = coins[i][j];
      if (i == n - 1 && j == m - 1) {
        return k > 0 ? max(x, 0) : x;
      }
      int res = mem[i][j][k];
      if (res != kMin) {
        return res;
      }
      res = max(dfs(i + 1, j, k), dfs(i, j + 1, k)) + x;
      if (k > 0 && x < 0) {
        res = max({res, dfs(i + 1, j, k - 1), dfs(i, j + 1, k - 1)});
      }
      return mem[i][j][k] = res;
    };
    return dfs(0, 0, 2);
  }
};