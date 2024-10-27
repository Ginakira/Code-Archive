// 冗余连接
#include <vector>
using namespace std;

// 裸并查集
class Solution {
   private:
    struct UnoinSet {
        int *father;

        UnoinSet(int n) {
            father = new int[n];
            for (int i = 0; i < n; ++i) father[i] = i;
        }

        int find(int x) {
            return x == father[x] ? x : father[x] = find(father[x]);
        }

        int merge(int a, int b) {
            int ra = find(a), rb = find(b);
            if (ra == rb) return 0;
            father[rb] = ra;
            return 1;
        }

        ~UnoinSet() { delete[] father; }
    };

   public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        UnoinSet u(edges.size() + 5);
        vector<int> ret;
        for (const auto &edge : edges) {
            if (!u.merge(edge[0], edge[1])) {
                ret.emplace_back(edge[0]);
                ret.emplace_back(edge[1]);
                break;
            }
        }
        return ret;
    }
};

class Solution2 {
   private:
    class UnionFind {
       public:
        UnionFind(size_t n) : parent_(n + 1) {
            for (int i = 1; i <= n; ++i) {
                parent_[i] = i;
            }
        }

        int Find(int idx) {
            if (parent_[idx] != idx) {
                parent_[idx] = Find(parent_[idx]);
            }
            return parent_[idx];
        }

        void Union(int u, int v) { parent_[Find(u)] = parent_[Find(v)]; }

       private:
        vector<int> parent_;
    };

   public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        size_t n = edges.size();
        UnionFind uf(n);
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1];
            if (uf.Find(u) != uf.Find(v)) {
                uf.Union(u, v);
            } else {
                return edge;
            }
        }
        return {};
    }
};