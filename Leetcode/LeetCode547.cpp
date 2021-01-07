// 朋友圈
#include <vector>
using namespace std;

// 带路径压缩的裸的并查集 16ms
class Solution {
   public:
    struct UnionSet {
        int* father;
        int n;

        UnionSet(int n) : n(n) {
            father = new int[n];
            for (int i = 0; i < n; ++i) father[i] = i;
        }

        int find(int x) { return x == father[x] ? x : find(father[x]); }

        void merge(int a, int b) {
            int ra = find(a), rb = find(b);
            if (ra == rb) return;
            father[rb] = ra;
            return;
        }

        int getRootCount() {
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (father[i] == i) ++cnt;
            }
            return cnt;
        }

        ~UnionSet() { delete[] father; }
    };

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UnionSet u(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isConnected[i][j] == 1) {
                    u.merge(i, j);
                }
            }
        }
        return u.getRootCount();
    }
};