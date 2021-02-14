// LeetCode 765 情侣牵手
#include <unordered_map>
#include <vector>
using namespace std;

// 并查集
// 将座位想象成双人沙发
class UnionFind {
   private:
    int setCount = 0;
    vector<int> father;

   public:
    UnionFind(int n) : setCount(n), father(n) {
        for (int i = 0; i < n; ++i) {
            father[i] = i;
        }
    }

    int find(int x) { return father[x] == x ? x : father[x] = find(father[x]); }

    void merge(int a, int b) {
        int fa = find(a), fb = find(b);
        if (fa == fb) return;
        father[fb] = fa;
        --setCount;
        return;
    }

    int getSetCount() { return setCount; }
};

class Solution {
   public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        unordered_map<int, int> couch;
        for (int i = 0; i < n; ++i) {
            couch[row[i]] = i / 2;
        }
        UnionFind uf(n / 2);
        for (int i = 0; i < n; i += 2) {
            uf.merge(couch[i], couch[i + 1]);
        }
        return n / 2 - uf.getSetCount();
    }
};