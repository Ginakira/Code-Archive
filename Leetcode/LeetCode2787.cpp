// LeetCode 2787 将一个数字表示成幂的和的方案数

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
  int numberOfWays(int n, int x) {
    vector<long long> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; pow(i, x) <= n; ++i) {
      int cur = pow(i, x);
      for (int j = n; j >= cur; --j) {
        dp[j] += dp[j - cur];
      }
    }
    static constexpr int MOD = 1e9 + 7;
    return dp[n] % MOD;
  }
};
