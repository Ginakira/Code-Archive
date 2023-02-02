// LeetCode 1129 颜色交替的最短路径

#include <algorithm>
#include <numeric>
#include <queue>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges,
                                         vector<vector<int>> &blueEdges) {
        vector<vector<vector<int>>> graph(2, vector<vector<int>>(n));
        for (auto &e : redEdges) {
            graph[0][e[0]].emplace_back(e[1]);
        }
        for (auto &e : blueEdges) {
            graph[1][e[0]].emplace_back(e[1]);
        }

        vector<vector<bool>> vis(n, vector<bool>(2, false));
        vector<int> ans(n, -1);
        queue<tuple<int /* edge */, int /* color */>> q;

        q.emplace(0, 0);
        q.emplace(0, 1);
        int dis = 0;

        while (!q.empty()) {
            for (int _ = q.size(); _; --_) {
                auto [edge, color] = q.front();
                q.pop();
                if (ans[edge] == -1) {
                    ans[edge] = dis;
                }
                vis[edge][color] = true;
                color = !color;
                for (auto &next_edge : graph[color][edge]) {
                    if (!vis[next_edge][color]) {
                        q.emplace(next_edge, color);
                    }
                }
            }
            ++dis;
        }

        return ans;
    }
};