// LeetCode 3650 边反转的最小路径总成本

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
  int minCost(int n, vector<vector<int>>& edges) {
    using PII = pair<int, int>;
    vector<vector<PII>> g(n);
    for (const auto& e : edges) {
      int x = e[0], y = e[1], w = e[2];
      g[x].emplace_back(y, w);
      g[y].emplace_back(x, w * 2);
    }

    vector<int> dis(n, numeric_limits<int>::max());
    priority_queue<PII, vector<PII>, greater<>> pq;
    dis[0] = 0;
    pq.emplace(0, 0);
    while (!pq.empty()) {
      auto [dis_x, x] = pq.top();
      pq.pop();
      if (dis_x > dis[x]) {
        continue;
      }
      if (x == n - 1) {
        return dis_x;
      }
      for (const auto& [y, w] : g[x]) {
        auto new_dis_y = dis_x + w;
        if (new_dis_y < dis[y]) {
          dis[y] = new_dis_y;
          pq.emplace(new_dis_y, y);
        }
      }
    }
    return -1;
  }
};