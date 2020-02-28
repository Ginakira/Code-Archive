// 朋友圈
#include <vector>
using namespace std;

// 带路径压缩的裸的并查集 16ms
class Solution {
   public:
    int father[233];

    void init() {
        for (int i = 0; i < 233; ++i) {
            father[i] = i;
        }
        return;
    }

    int find(int x) {
        return father[x] = (father[x] == x ? x : find(father[x]));
    }

    int merge(int a, int b) {
        int fa = find(a), fb = find(b);
        if (fa == fb) return 0;
        father[fa] = fb;
        return 1;
    }

    int findCircleNum(vector<vector<int>>& M) {
        init();
        int n = M.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (M[i][j] == 1) merge(i, j);
            }
        }
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            if (father[i] == i) ret++;
        }
        return ret;
    }
};