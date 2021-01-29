// LeetCode 1631 最小体力消耗路径
#include <algorithm>
#include <vector>
using namespace std;

class UnionFind {
   private:
    vector<int> father;
    int setCount;

   public:
    UnionFind(int n) : father(n), setCount(n) {
        for (int i = 0; i < n; ++i) father[i] = i;
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
};

class Solution {
   public:
    int minimumEffortPath(vector<vector<int>> &heights) {
        int rows = heights.size(), cols = heights[0].size();
        int n = rows * cols;
        UnionFind uf(n);
        vector<tuple<int, int, int>> edges;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int id = i * cols + j;
                if (i > 0) {
                    edges.emplace_back(id - cols, id,
                                       abs(heights[i][j] - heights[i - 1][j]));
                }
                if (j > 0) {
                    edges.emplace_back(id - 1, id,
                                       abs(heights[i][j] - heights[i][j - 1]));
                }
            }
        }
        sort(edges.begin(), edges.end(),
             [](const auto &a, const auto &b) -> bool {
                 auto &&[fa, ta, ca] = a;
                 auto &&[fb, tb, cb] = b;
                 return ca < cb;
             });

        int target = n - 1, ans = 0;
        for (const auto &[from, to, cost] : edges) {
            uf.merge(from, to);
            if (uf.connected(0, target)) {
                ans = cost;
                break;
            }
        }
        return ans;
    }
};