// LeetCode 3243 新增道路查询后的最短距离 I

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
    vector<int> shortestDistanceAfterQueries(int n,
                                             vector<vector<int>>& queries) {
        vector<int> dis(n);
        vector<vector<int>> outdeg(n);
        vector<vector<int>> indeg(n);
        vector<int> ans;
        ans.reserve(queries.size());
        iota(dis.rbegin(), dis.rend(), 0);
        for (int i = 0; i < n; ++i) {
            if (i < n - 1) {
                outdeg[i].emplace_back(i + 1);
            }
            if (i > 0) {
                indeg[i].emplace_back(i - 1);
            }
        }
        for (const auto& query : queries) {
            int u = query[0], v = query[1];
            outdeg[u].emplace_back(v);
            indeg[v].emplace_back(u);
            // update dis
            for (int deg : outdeg[u]) {
                dis[u] = min(dis[u], dis[deg] + 1);
            }
            for (int i = u - 1; i >= 0; --i) {
                for (int deg : outdeg[i]) {
                    dis[i] = min(dis[i], dis[deg] + 1);
                }
            }

            ans.emplace_back(dis[0]);
        }
        return ans;
    }
};

class Solution2 {
   public:
    vector<int> shortestDistanceAfterQueries(int n,
                                             vector<vector<int>>& queries) {
        vector<int> dis(n);
        vector<vector<int>> outdeg(n);
        vector<int> ans;
        ans.reserve(queries.size());
        iota(dis.rbegin(), dis.rend(), 0);
        for (int i = 0; i < n - 1; ++i) {
            outdeg[i].emplace_back(i + 1);
        }
        for (const auto& query : queries) {
            int u = query[0], v = query[1];
            outdeg[u].emplace_back(v);
            // update dis
            for (int i = u; i >= 0; --i) {
                for (int deg : outdeg[i]) {
                    dis[i] = min(dis[i], dis[deg] + 1);
                }
            }

            ans.emplace_back(dis[0]);
        }
        return ans;
    }
};

class Solution3 {
   public:
    vector<int> shortestDistanceAfterQueries(int n,
                                             vector<vector<int>>& queries) {
        vector<vector<int>> in_deg(n);
        vector<int> dis(n);
        for (int i = 1; i < n; ++i) {
            in_deg[i].emplace_back(i - 1);
            dis[i] = i;
        }
        vector<int> ans;
        ans.reserve(queries.size());
        for (const auto& query : queries) {
            int u = query[0], v = query[1];
            in_deg[v].emplace_back(u);
            for (int i = v; i < n; ++i) {
                for (int deg : in_deg[i]) {
                    dis[i] = min(dis[i], dis[deg] + 1);
                }
            }
            ans.emplace_back(dis[n - 1]);
        }
        return ans;
    }
};