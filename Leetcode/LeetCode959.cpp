// LeetCode 959 由斜杠划分区域
#include <string>
#include <vector>
using namespace std;

// 并查集
// 将每一个单元格都分为四个三角形，顺时针编号分别为0-3
// 根据斜线将这些三角形进行合并
// 注意每次合并后，将1号与右边的3试图进行合并，将2号与下边的0进行合并
class UnionFind {
   private:
    vector<int> father;
    int count;

   public:
    UnionFind(int n) : father(n), count(n) {
        for (int i = 0; i < n; ++i) {
            father[i] = i;
        }
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
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        UnionFind uf(n * n * 4);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int idx = i * n + j, idn = idx * 4;
                if (i < n - 1) {
                    int bottom = (idx + n) * 4;
                    uf.merge(idn + 2, bottom);
                }
                if (j < n - 1) {
                    int right = (idx + 1) * 4;
                    uf.merge(idn + 1, right + 3);
                }
                if (grid[i][j] == '/') {
                    uf.merge(idn, idn + 3);
                    uf.merge(idn + 1, idn + 2);
                } else if (grid[i][j] == '\\') {
                    uf.merge(idn, idn + 1);
                    uf.merge(idn + 2, idn + 3);
                } else {
                    uf.merge(idn, idn + 1);
                    uf.merge(idn + 1, idn + 2);
                    uf.merge(idn + 2, idn + 3);
                }
            }
        }
        return uf.getCount();
    }
};