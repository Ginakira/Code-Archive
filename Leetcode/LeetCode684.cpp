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