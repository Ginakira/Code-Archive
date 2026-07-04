// LeetCode 2492 两个城市间路径的最小分数

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
  int minScore(int n, vector<vector<int>>& roads) {
    vector<vector<tuple<int, int>>> g(n + 1);
    for (const auto& e : roads) {
      int x = e[0], y = e[1], d = e[2];
      g[x].emplace_back(y, d);
      g[y].emplace_back(x, d);
    }

    vector<bool> vis(n + 1);
    int ans = numeric_limits<int>::max();
    auto dfs = [&](this auto&& dfs, int x) -> void {
      vis[x] = true;
      for (auto& [y, dis] : g[x]) {
        ans = min(ans, dis);
        if (!vis[y]) {
          dfs(y);
        }
      }
    };
    dfs(1);
    return ans;
  }
};