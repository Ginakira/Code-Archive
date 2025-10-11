// LeetCode 3186 施咒的最大总伤害

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
  long long maximumTotalDamage(vector<int>& power) {
    map<int, int> cnt;
    for (int p : power) {
      ++cnt[p];
    }
    vector<pair<int, int>> a(cnt.begin(), cnt.end());

    int n = a.size();
    vector<long long> mem(n, -1);
    auto dfs = [&](auto&& dfs, int i) -> long long {
      if (i < 0) {
        return 0;
      }
      long long& res = mem[i];
      if (res != -1) {
        return res;
      }

      auto& [x, c] = a[i];
      int j = i;
      while (j && a[j - 1].first >= x - 2) {
        --j;
      }
      res = max(dfs(dfs, i - 1), dfs(dfs, j - 1) + 1LL * x * c);
      return res;
    };
    return dfs(dfs, n - 1);
  }
};