// LeetCode 3558 给边赋权值的方案数 I
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
  const int MOD = 1'000'000'007;

  long long qpow(long long x, int n) {
    long long res = 1;
    for (; n > 0; n /= 2) {
      if (n % 2) {
        res = res * x % MOD;
      }
      x = x * x % MOD;
    }
    return res;
  }

 public:
  int assignEdgeWeights(vector<vector<int>>& edges) {
    int n = edges.size() + 1;
    vector<vector<int>> g(n + 1);
    for (auto& e : edges) {
      int x = e[0], y = e[1];
      g[x].push_back(y);
      g[y].push_back(x);
    }

    auto dfs = [&](this auto&& dfs, int x, int fa) -> int {
      int d = 0;
      for (int y : g[x]) {
        if (y != fa) {
          d = max(d, dfs(y, x) + 1);
        }
      }
      return d;
    };

    int k = dfs(1, 0);
    return qpow(2, k - 1);
  }
};