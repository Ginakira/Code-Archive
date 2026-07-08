// LeetCode 3756 连接非零数字并乘以其数字和 II

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
  vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
    static constexpr int MOD = 1e9 + 7;
    static constexpr int MAX_N = 1e5 + 1;

    std::array<int, MAX_N> pow10{1};
    for (int i = 1; i < MAX_N; ++i) {
      pow10[i] = pow10[i - 1] * 10LL % MOD;
    }

    int n = s.size();
    vector<int> sum_d(n + 1), pre_num(n + 1), sum_non_zero(n + 1);
    for (int i = 0; i < n; ++i) {
      int d = s[i] - '0';
      sum_d[i + 1] = sum_d[i] + d;
      pre_num[i + 1] = d > 0 ? (pre_num[i] * 10LL + d) % MOD : pre_num[i];
      sum_non_zero[i + 1] = sum_non_zero[i] + (d > 0);
    }

    vector<int> ans;
    ans.reserve(queries.size());
    for (const auto& q : queries) {
      int l = q[0], r = q[1] + 1;
      int len = sum_non_zero[r] - sum_non_zero[l];
      long long x = pre_num[r] - 1LL * pre_num[l] * pow10[len] % MOD + MOD;
      ans.emplace_back(x * (sum_d[r] - sum_d[l]) % MOD);
    }
    return ans;
  }
};