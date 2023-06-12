// LeetCode 1483 树节点的第K个祖先

#include <algorithm>
#include <array>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class TreeAncestor {
   private:
    vector<vector<int>> pa;

   public:
    TreeAncestor(int n, vector<int>& parent) {
        int m = 32 - __builtin_clz(n);  // n 的二进制长度
        pa.resize(n, vector<int>(m, -1));

        for (int i = 0; i < n; ++i) {
            pa[i][0] = parent[i];
        }

        for (int i = 0; i < m - 1; ++i) {
            for (int x = 0; x < n; ++x) {
                if (int p = pa[x][i]; p != -1) {
                    pa[x][i + 1] = pa[p][i];
                }
            }
        }
    }

    int getKthAncestor(int node, int k) {
        int cur_node = node;
        int m = 32 - __builtin_clz(k);
        for (int i = 0; i < m; ++i) {
            if ((k >> i) & 1) {
                node = pa[node][i];
                if (node < 0) {
                    break;
                }
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */