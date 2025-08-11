// LeetCode 2438 二的幂数组中查询范围内的乘积

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
  vector<int> productQueries(int n, vector<vector<int>>& queries) {
    vector<int> powers;
    int cur = 1;
    while (n) {
      if (n & 1) {
        powers.emplace_back(cur);
      }
      cur <<= 1;
      n >>= 1;
    }
    vector<int> answers;
    answers.reserve(queries.size());
    constexpr int MOD = 1e9 + 7;
    for (const auto& query : queries) {
      long long mul = 1;
      int l = query[0], r = query[1];
      for (int j = l; j <= r; ++j) {
        mul = mul * powers[j] % MOD;
      }
      answers.emplace_back(mul);
    }
    return answers;
  }
};