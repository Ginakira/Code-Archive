// LeetCode 802 找到最终的安全状态
#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// DFS + 标记
// 0 未访问过的结点 1 在递归栈中或已经确定在环上的点 2 确认安全的点
class Solution {
   private:
    static constexpr int NORMAL = 0, RECURSIVE = 1, SAFE = 2;

   public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, NORMAL);

        function<bool(int)> is_safe = [&](int node) {
            if (color[node] > NORMAL) {
                return color[node] == SAFE;
            }

            color[node] = RECURSIVE;
            for (const int& next_node : graph[node]) {
                if (!is_safe(next_node)) {
                    return false;
                }
            }
            color[node] = SAFE;
            return true;
        };

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (is_safe(i)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};