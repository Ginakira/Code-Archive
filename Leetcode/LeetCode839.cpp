// LeetCode 839 相似字符串组
#include <string>
#include <vector>
using namespace std;

// 并查集
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
    int numSimilarGroups(vector<string> &strs) {
        int n = strs.size();
        UnionFind uf(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (uf.connected(i, j)) continue;
                if (isSimilar(strs[i], strs[j])) {
                    uf.merge(i, j);
                }
            }
        }
        return uf.getSetCount();
    }

    bool isSimilar(const string &a, const string &b) {
        int count = 0, n = a.size();
        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) {
                ++count;
                if (count > 2) {
                    return false;
                }
            }
        }
        return true;
    }
};