// LeetCode 1579 保证图可完全遍历
#include <vector>
using namespace std;

class UnionFind {
   private:
    vector<int> father;
    int setCount;

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

    int getSetCount() { return setCount; }
};

class Solution {
   public:
    int maxNumEdgesToRemove(int n, vector<vector<int>> &edges) {
        UnionFind uf(n);
        int ans = 0;

        // 优先合并公共边
        for (auto &edge : edges) {
            // 将点的编号改为从0开始
            --edge[1];
            --edge[2];
            if (edge[0] != 3) continue;
            if (!uf.merge(edge[1], edge[2])) {
                ++ans;
            }
        }

        // 在上一步的基础上，单独维护并查集，单独合并
        UnionFind auf = uf, buf = uf;
        for (const auto &edge : edges) {
            if (edge[0] == 3) continue;
            UnionFind &uf_tmp = edge[0] == 1 ? auf : buf;
            if (!uf_tmp.merge(edge[1], edge[2])) {
                ++ans;
            }
        }

        if (auf.getSetCount() != 1 || buf.getSetCount() != 1) {
            return -1;
        }
        return ans;
    }
};