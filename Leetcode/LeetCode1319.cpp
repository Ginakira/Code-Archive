// LeetCode 1319 连通网络的操作次数
#include <vector>
using namespace std;

// 并查集 求最终连通块数量与冗余边的数量
// 如果连通块数量-1小于冗余边的数量(冗余边够用)
// 则可以将剩余的连通块使用连通块数量 - 1条边连接起来
class UnionFind {
   private:
    vector<int> father;
    int count;

   public:
    UnionFind(int n) : father(n), count(n) {
        for (int i = 0; i < n; ++i) father[i] = i;
    }

    int find(int x) { return father[x] == x ? x : father[x] = find(father[x]); }

    bool merge(int a, int b) {
        int fa = find(a), fb = find(b);
        if (fa == fb) return false;
        father[fb] = fa;
        --count;
        return true;
    }

    int getCount() { return count; }
};

class Solution {
   public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        UnionFind uf(n);
        int redundant = 0;
        for (auto& connection : connections) {
            if (!uf.merge(connection[0], connection[1])) {
                ++redundant;
            }
        }
        if (uf.getCount() - 1 > redundant) {
            return -1;
        }
        return uf.getCount() - 1;
    }
};