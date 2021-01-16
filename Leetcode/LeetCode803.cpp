// LeetCode 803 打砖块
#include <vector>
using namespace std;

// 并查集 逆向思考 370ms
class UnionFind {
   private:
    vector<int> father, count;

   public:
    UnionFind(int n) : father(n), count(n) {
        for (int i = 0; i < n; ++i) {
            father[i] = i;
            count[i] = 1;
        }
    }

    int find(int x) { return father[x] == x ? x : father[x] = find(father[x]); }

    void merge(int a, int b) {
        int fa = find(a), fb = find(b);
        if (fa == fb) return;
        father[fb] = fa;
        count[fa] += count[fb];
        return;
    }

    int getCount(int x) { return count[find(x)]; }
};

class Solution {
   public:
    vector<int> hitBricks(vector<vector<int>>& grid,
                          vector<vector<int>>& hits) {
        int h = grid.size(), w = grid[0].size();
        UnionFind u(h * w + 1);
        vector<vector<int>> status = grid;

        // 得出最终状态
        for (const auto& hit : hits) {
            status[hit[0]][hit[1]] = 0;
        }

        // 根据最终状态初始化并查集
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (status[i][j] == 0) continue;
                if (i ==
                    0) {  // 如果是第一行的，代表与墙相连，这些点都与一个特殊的节点h
                          // * w相连
                    u.merge(h * w, i * w + j);
                }
                // 由于我们从上至下从左至右遍历，所以只考虑左面上面有没有砖块相连即可，有则进行合并
                if (i > 0 && status[i - 1][j] == 1) {
                    u.merge(i * w + j, (i - 1) * w + j);
                }
                if (j > 0 && status[i][j - 1] == 1) {
                    u.merge(i * w + j, i * w + j - 1);
                }
            }
        }

        vector<int> ret(hits.size());
        const vector<pair<int, int>> direction = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        // 倒序遍历hits
        // 正向的逻辑：按顺序打碎砖块，每删除一个点，可能会使一个连通块分裂为两个连通块。
        // 但并查集能实现的是将点合并，可能会使不同的连通块连接合并为一个连通块
        // 所以我们可以逆向思考，将最后的打碎操作全部执行完后的状态作为初始状态，将hit操作逆向看成是往上添加砖块
        // 每次添加砖块后与墙相连的那个连通块节点增加的数量，就是正向打碎时会掉落的节点数
        for (int i = hits.size() - 1; i >= 0; --i) {
            int r = hits[i][0], c = hits[i][1];
            if (grid[r][c] == 0) continue;
            int prev = u.getCount(h * w);
            if (r == 0) {
                u.merge(h * w, r * w + c);
            }
            for (const auto& [dr, dc] : direction) {
                int nr = r + dr, nc = c + dc;
                // 补上这块砖之前稳定的砖块（与特殊节点相连）
                if (nr >= 0 && nr < h && nc >= 0 && nc < w &&
                    status[nr][nc] == 1) {
                    u.merge(r * w + c, nr * w + nc);
                }
            }
            ret[i] = max(0, u.getCount(h * w) - prev - 1);
            status[r][c] = 1;
        }
        return ret;
    }
};