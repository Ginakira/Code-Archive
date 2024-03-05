// LeetCode 1976 到达目的地的方案数

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
    int countPaths(int n, vector<vector<int>> &roads) {
        typedef long long LL;
        constexpr static LL MOD = 1e9 + 7;
        vector<vector<pair<int, int>>> e(n);
        for (const auto &road : roads) {
            int u = road[0], v = road[1], w = road[2];
            e[u].emplace_back(v, w);
            e[v].emplace_back(u, w);
        }
        vector<LL> dis(n, numeric_limits<LL>::max());
        vector<LL> ways(n);

        priority_queue<pair<LL, int>, vector<pair<LL, int>>,
                       greater<pair<LL, int>>>
            pq;
        pq.emplace(0, 0);
        dis[0] = 0;
        ways[0] = 1;

        while (!pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();
            if (cost > dis[u]) {
                continue;
            }
            for (auto &[v, w] : e[u]) {
                LL new_cost = cost + w;
                if (new_cost < dis[v]) {
                    dis[v] = new_cost;
                    ways[v] = ways[u];
                    pq.emplace(new_cost, v);
                } else if (new_cost == dis[v]) {
                    ways[v] = (ways[u] + ways[v]) % MOD;
                }
            }
        }
        return ways[n - 1];
    }
};
