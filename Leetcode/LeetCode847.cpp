// LeetCode 847 访问所有节点的最短路径

#include <algorithm>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 使用位运算标记 mask的第i位表示第i个结点是否走过 然后BFS即可
class Solution {
   public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<tuple<int, int, int>> que;
        vector<vector<int>> seen(n, vector<int>(1 << n));

        for (int i = 0; i < n; ++i) {
            que.emplace(i, 1 << i, 0);
            seen[i][1 << i] = true;
        }

        int ans = 0;
        while (!que.empty()) {
            auto [from, mask, steps] = que.front();
            que.pop();

            if (mask == (1 << n) - 1) {
                ans = steps;
                break;
            }

            for (const int& to : graph[from]) {
                int to_mask = mask | (1 << to);
                if (!seen[to][to_mask]) {
                    que.emplace(to, to_mask, steps + 1);
                    seen[to][to_mask] = true;
                }
            }
        }
        return ans;
    }
};