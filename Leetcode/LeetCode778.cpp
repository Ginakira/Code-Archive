// LeetCode 778 水位上升的泳池中游泳
#include <algorithm>
#include <vector>
using namespace std;

// 并查集 + 边权值排序 权值为两点高度较大的一个
class UnionFind {
   public:
    UnionFind(int n) : father(n), setCount(n) {
        for (int i = 0; i < n; ++i) {
            father[i] = i;
        }
    }

    int find(int x) { return father[x] == x ? x : father[x] = find(father[x]); }

    bool merge(int a, int b) {
        int fa = find(a), fb = find(b);
        if (fa == fb) return false;
        father[fb] = fa;
        --setCount;
        return true;
    }

    bool connected(int a, int b) { return find(a) == find(b); }

    int getSetCount() { return setCount; }

   private:
    vector<int> father;
    int setCount;
};

class Solution {
   public:
    int swimInWater(vector<vector<int>> &grid) {
        int n = grid.size();
        vector<tuple<int, int, int>> edges;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int id = i * n + j;
                if (i > 0) {
                    edges.emplace_back(id - n, id,
                                       max(grid[i][j], grid[i - 1][j]));
                }
                if (j > 0) {
                    edges.emplace_back(id - 1, id,
                                       max(grid[i][j], grid[i][j - 1]));
                }
            }
        }

        sort(edges.begin(), edges.end(),
             [](const auto &a, const auto &b) -> bool {
                 auto &[fa, ta, ca] = a;
                 auto &[fb, tb, cb] = b;
                 return ca < cb;
             });

        int target = n * n - 1, ans = 0;
        UnionFind uf(target + 1);
        for (const auto &edge : edges) {
            auto &[from, to, cost] = edge;
            uf.merge(from, to);
            if (uf.connected(0, target)) {
                ans = cost;
                break;
            }
        }
        return ans;
    }
};