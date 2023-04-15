// LeetCode 1042 不邻接植花

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
    vector<vector<int>> graph;
    vector<int> ans;

    bool dfs(int target, int color) {
        ans[target] = color;
        for (auto &child : graph[target]) {
            if (ans[child] == color) {
                return false;
            } else if (ans[child] != 0) {
                continue;
            }
            for (int i = 1; i <= 4; ++i) {
                if (dfs(child, i)) {
                    ans[child] = i;
                    break;
                }
            }
        }
        return true;
    }

   public:
    vector<int> gardenNoAdj(int n, vector<vector<int>> &paths) {
        graph.resize(n, vector<int>());
        ans.resize(n, 0);

        for (const auto &path : paths) {
            int u = path[0] - 1, v = path[1] - 1;
            graph[u].emplace_back(v);
            graph[v].emplace_back(u);
        }
        for (int i = 0; i < n; ++i) {
            if (ans[i] == 0) {
                dfs(i, 1);
            }
        }
        return ans;
    }
};