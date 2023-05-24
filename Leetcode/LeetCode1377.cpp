// LeetCode 1377 T秒后青蛙的位置

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
   private:
    double dfs(vector<vector<int>> &g, vector<bool> &vis, int cur, int t,
               int target) {
        int choice_cnt = cur == 1 ? g[cur].size() : g[cur].size() - 1;
        if (t == 0 || choice_cnt == 0) {
            return cur == target ? 1.0 : 0.0;
        }
        vis[cur] = true;
        double ans = 0;
        for (auto e : g[cur]) {
            if (!vis[e]) {
                ans += dfs(g, vis, e, t - 1, target);
            }
        }
        return ans / choice_cnt;
    }

   public:
    double frogPosition(int n, vector<vector<int>> &edges, int t, int target) {
        // build graph
        vector<vector<int>> g(n + 1);
        vector<bool> vis(n + 1, false);
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1];
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        return dfs(g, vis, 1, t, target);
    }
};