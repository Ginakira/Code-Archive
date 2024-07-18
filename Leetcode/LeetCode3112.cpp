// LeetCode 3112 访问消失节点的最少时间

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
    vector<int> minimumTime(int n, vector<vector<int>>& edges,
                            vector<int>& disappear) {
        vector<vector<tuple<int, int>>> g(n);
        for (const auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
        }
        priority_queue<tuple<int, int>, vector<tuple<int, int>>,
                       greater<tuple<int, int>>>
            pq;
        pq.emplace(0, 0);
        vector<int> ans(n, -1);
        ans[0] = 0;
        while (!pq.empty()) {
            auto [time, u] = pq.top();
            pq.pop();
            if (time != ans[u]) {
                continue;
            }
            for (const auto& [v, w] : g[u]) {
                if (time + w < disappear[v] &&
                    (ans[v] == -1 || time + w < ans[v])) {
                    pq.emplace(time + w, v);
                    ans[v] = time + w;
                }
            }
        }
        return ans;
    }
};