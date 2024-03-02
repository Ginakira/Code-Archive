// LeetCode 2368 受限条件下可到达节点的数目

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
    int reachableNodes(int n, vector<vector<int>>& edges,
                       vector<int>& restricted) {
        unordered_set<int> banned(restricted.begin(), restricted.end());
        vector<vector<int>> g(n, vector<int>{});
        for (auto& e : edges) {
            g[e[0]].emplace_back(e[1]);
            g[e[1]].emplace_back(e[0]);
        }
        int ans = 0;
        function<void(int, int)> dfs = [&](int cur, int pre) {
            ++ans;
            for (auto e : g[cur]) {
                if (e != pre && !banned.count(e)) {
                    dfs(e, cur);
                }
            }
        };
        dfs(0, -1);
        return ans;
    }
};