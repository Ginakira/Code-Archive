// LeetCdoe 785 判断二分图
#include <vector>
using namespace std;

// 染色法+DFS
// 因为符合二分图的定义要求是，每条边的两个节点都不能属于同一个集合
// 所以我们将节点染成两种颜色，作为不同集合的区分
// 从未染色的点开始，假设染成红色，那么根据给出的邻接关系，所有有边与它相连的
// 都应该染成绿色，反之亦然
// 如果在染色的过程中发现要染色的点已经有颜色了，并且颜色还与想涂成的颜色不一致
// 则可以判定，这个图不可能是一个二分图
class Solution {
   private:
    static constexpr int UNCOLORED = 0;
    static constexpr int RED = 1;
    static constexpr int GREEN = 2;
    vector<int> color;
    bool valid;

   public:
    void dfs(int node_id, int paint_color, vector<vector<int>>& graph) {
        color[node_id] = paint_color;
        int neighbor_color = (paint_color == RED ? GREEN : RED);
        for (int neighbor_id : graph[node_id]) {
            if (color[neighbor_id] == UNCOLORED) {
                dfs(neighbor_id, neighbor_color, graph);
                if (!valid) return;
            } else if (color[neighbor_id] != neighbor_color) {
                valid = false;
                return;
            }
        }
        return;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        color.assign(n, UNCOLORED);
        valid = true;
        for (int i = 0; i < n && valid; ++i) {
            if (color[i] == UNCOLORED) {
                dfs(i, RED, graph);
            }
        }
        return valid;
    }
};