// LeetCode 947 移除最多的同行货同列石头
#include <unordered_map>
#include <vector>
using namespace std;

// S1 DFS 600ms
// 遍历所有点（石头），如果两个点处于同一行或同一列，则可视为两点间有一条边
// （即图中存储的是石头与石头之间的关系，如果两个石头之间有边则代表它们在同一列或同一行上）
// 依据此建图，最后使用DFS统计有多少个连通块即可，总石头数 - 连通块数即为答案
// 因为策略是尽可能后删除同一行同一列都有的点，所以DFS的操作顺序倒序即为删除的顺序
// 一定有方法能够将一个连通块删除到只剩一个节点
class Solution {
   public:
    int removeStones(vector<vector<int>> &stones) {
        int n = stones.size();
        vector<vector<int>> edges(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (stones[i][0] == stones[j][0] ||
                    stones[i][1] == stones[j][1]) {
                    edges[i].push_back(j);
                }
            }
        }
        vector<bool> vis(n, false);
        int num = 0;
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                ++num;
                dfs(i, edges, vis);
            }
        }
        return n - num;
    }

    void dfs(int x, vector<vector<int>> &edges, vector<bool> &vis) {
        vis[x] = true;
        for (auto &edge : edges[x]) {
            if (!vis[edge]) {
                dfs(edge, edges, vis);
            }
        }
        return;
    }
};

// 优化建图 + DFS 68ms
// 因为在同一行或者同一列这个条件具有传递性，所以我们可以假定n个点我们恰好可以使用n-1条边链接起来
// 所以我们可以遍历石头，将在同一行同一列的点使用哈希表分别存储起来
// 因为坐标是二维的，且x最大值为1e4,所以为了不建立两个哈希表，我们可以在y坐标加上1e4作为key，防止与x坐标冲突
// 最后我们遍历哈希表，将处于同一行同一列的这些石头编号两两建边
// 其他步骤同S1
class Solution2 {
   public:
    int removeStones(vector<vector<int>> &stones) {
        int n = stones.size();
        vector<vector<int>> edges(n);
        unordered_map<int, vector<int>> rec;
        for (int i = 0; i < n; ++i) {
            rec[stones[i][0]].push_back(i);
            // 因为x最大值为1e4
            // 所以可以加在纵坐标上将横纵坐标存储在一个哈希表里
            rec[stones[i][1] + 100000].push_back(i);
        }

        for (auto &[_, vec] : rec) {
            int k = vec.size();
            // 两两建边
            for (int i = 1; i < k; ++i) {
                edges[vec[i - 1]].push_back(vec[i]);
                edges[vec[i]].push_back(vec[i - 1]);
            }
        }

        vector<bool> vis(n, false);
        int num = 0;
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                ++num;
                dfs(i, edges, vis);
            }
        }
        return n - num;
    }

    void dfs(int x, vector<vector<int>> &edges, vector<bool> &vis) {
        vis[x] = true;
        for (auto &edge : edges[x]) {
            if (!vis[edge]) {
                dfs(edge, edges, vis);
            }
        }
        return;
    }
};

// 优化建图 + 并查集 40ms
// 在此方法中，我们合并的是每个石头的横纵坐标
// 【【【【重要：合并横纵坐标x,y的语义是x行上所有的石头与y列上所有的石头都属于同一个联通分量】】】】
// 纵坐标的处理方式同S2
class Solution3 {
   private:
    struct UnionSet {
        unordered_map<int, int> father;
        int find(int x) {
            if (father.find(x) == father.end()) {
                father[x] = x;
                return x;
            }
            return father[x] == x ? x : father[x] = find(father[x]);
        }

        void merge(int a, int b) {
            int fa = find(a), fb = find(b);
            if (fa == fb) return;
            father[fb] = fa;
        }

        int getRootNum() {
            int cnt = 0;
            for (auto &[x, fa] : father) {
                if (x == fa) ++cnt;
            }
            return cnt;
        }
    };

   public:
    int removeStones(vector<vector<int>> &stones) {
        UnionSet u;
        for (auto &stone : stones) {
            u.merge(stone[0], stone[1] + 10001);
        }
        return stones.size() - u.getRootNum();
    }
};