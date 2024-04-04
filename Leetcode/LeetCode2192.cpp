// LeetCode 2192 有向无环图中一个节点的所有祖先

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
    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges) {
        vector<unordered_set<int>> ancestors(n);
        vector<int> indeg(n);
        vector<vector<int>> outdeg(n);
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            outdeg[u].emplace_back(v);
            ++indeg[v];
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (!indeg[i]) {
                q.emplace(i);
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : outdeg[u]) {
                ancestors[v].insert(u);
                for (int i : ancestors[u]) {
                    ancestors[v].insert(i);
                }
                --indeg[v];
                if (!indeg[v]) {
                    q.push(v);
                }
            }
        }

        vector<vector<int>> ans(n);
        for (int i = 0; i < n; ++i) {
            for (auto &anc : ancestors[i]) {
                ans[i].emplace_back(anc);
            }
            ranges::sort(ans[i]);
        }
        return ans;
    }
};