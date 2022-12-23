// LeetCode 1971 寻找图中是否存在路径

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class UnionFind {
   public:
    UnionFind(int n) : father_(n, 0) {
        for (int i = 0; i < n; ++i) {
            father_[i] = i;
        }
    }

    void add(int a, int b) {
        int ra = find(a);
        int rb = find(b);
        if (ra == rb) {
            return;
        }
        father_[rb] = ra;
    }

    int find(int a) {
        if (father_[a] != a) {
            father_[a] = find(father_[a]);
        }
        return father_[a];
    }

    bool connected(int a, int b) { return find(a) == find(b); }

   private:
    vector<int> father_;
};

class Solution {
   public:
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        if (source == destination) {
            return true;
        }
        UnionFind uf(n);
        for (auto& edge : edges) {
            uf.add(edge[0], edge[1]);
        }
        return uf.connected(source, destination);
    }
};