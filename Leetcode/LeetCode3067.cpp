// LeetCode 3067 在带权树网络中统计可连接服务器对数目

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
    vector<int> countPairsOfConnectableServers(vector<vector<int>> &edges,
                                               int signalSpeed) {
        int n = edges.size() + 1;
        vector<vector<tuple<int, int>>> g(n);
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
        }
        function<int(int, int, int)> dfs = [&](int x, int fa, int sum) -> int {
            int cnt = sum % signalSpeed == 0;
            for (auto &[v, w] : g[x]) {
                if (v != fa) {
                    cnt += dfs(v, x, sum + w);
                }
            }
            return cnt;
        };

        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            if (g[i].size() == 1) {
                continue;
            }
            int sum = 0;
            for (auto &[v, w] : g[i]) {
                int cnt = dfs(v, i, w);
                ans[i] += cnt * sum;
                sum += cnt;
            }
        }
        return ans;
    }
};