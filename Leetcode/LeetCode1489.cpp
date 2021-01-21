// LeetCode 1489 找到最小生成树里的关键边和伪关键边
#include <algorithm>
#include <vector>
using namespace std;

// 枚举 + Kruskal最小生成树判定 113ms
class UnionFind {
   private:
    vector<int> father;
    int setCount;
    int n;

   public:
    UnionFind(int _n) : father(_n), setCount(_n), n(_n) {
        for (int i = 0; i < n; ++i) father[i] = i;
    }

    int getSetCount() { return setCount; }

    int find(int x) { return father[x] == x ? x : father[x] = find(father[x]); }

    bool merge(int a, int b) {
        int fa = find(a), fb = find(b);
        if (fa == fb) return false;
        father[fb] = fa;
        --setCount;
        return true;
    }
};

class Solution {
   public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(
        int n, vector<vector<int>> &edges) {
        int m = edges.size();
        for (int i = 0; i < m; ++i) {
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(),
             [](const auto &u, const auto &v) -> bool { return u[2] < v[2]; });
        // 求最小生成树
        int value = 0;
        UnionFind uf_std(n);
        for (const auto &edge : edges) {
            if (uf_std.merge(edge[0], edge[1])) {
                value += edge[2];
            }
        }
        // 枚举
        vector<vector<int>> ans(2);
        for (int i = 0; i < m; ++i) {
            // 判断关键边
            UnionFind uf(n);
            int v = 0;
            for (int j = 0; j < m; ++j) {
                if (i != j && uf.merge(edges[j][0], edges[j][1])) {
                    v += edges[j][2];
                }
            }
            if (uf.getSetCount() != 1 || (uf.getSetCount() == 1 && v > value)) {
                ans[0].push_back(edges[i][3]);
                continue;
            }
            // 判断伪关键边
            uf = UnionFind(n);
            uf.merge(edges[i][0], edges[i][1]);
            v = edges[i][2];
            for (int j = 0; j < m; ++j) {
                if (i != j && uf.merge(edges[j][0], edges[j][1])) {
                    v += edges[j][2];
                }
            }
            if (v == value) {
                ans[1].push_back(edges[i][3]);
            }
        }
        return ans;
    }
};