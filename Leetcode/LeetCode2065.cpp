// LeetCode 2065 最大化一张图中的路径价值

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
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges,
                           int maxTime) {
        int n = values.size();
        vector<vector<pair<int, int>>> g(n);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
        }

        vector<int> visited(n, false);
        visited[0] = true;
        int ans = 0;
        function<void(int, int, int)> dfs = [&](int u, int time, int value) {
            if (u == 0) {
                ans = max(ans, value);
            }
            for (const auto& [v, dis] : g[u]) {
                if (time + dis > maxTime) {
                    continue;
                }
                if (!visited[v]) {
                    visited[v] = true;
                    dfs(v, time + dis, value + values[v]);
                    visited[v] = false;
                } else {
                    dfs(v, time + dis, value);
                }
            }
        };
        dfs(0, 0, values[0]);
        return ans;
    }
};