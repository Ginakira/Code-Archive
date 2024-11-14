// LeetCode 3249 统计好节点的数目

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
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        int ans = 0;
        vector<vector<int>> g(n);
        for (const auto& e : edges) {
            g[e[0]].emplace_back(e[1]);
            g[e[1]].emplace_back(e[0]);
        }

        function<int(int, int)> dfs = [&](int node, int parent) {
            bool valid = true;
            int tree_size = 0;
            int sub_tree_size = 0;
            for (int child : g[node]) {
                if (child == parent) {
                    continue;
                }
                int size = dfs(child, node);
                if (sub_tree_size == 0) {
                    sub_tree_size = size;
                } else if (size != sub_tree_size) {
                    valid = false;
                }
                tree_size += size;
            }
            if (valid) {
                ++ans;
            }
            return tree_size + 1;
        };
        dfs(0, -1);
        return ans;
    }
};