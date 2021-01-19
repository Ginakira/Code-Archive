// LeetCode 1584 连接所有点的最小费用
#include <algorithm>
#include <climits>
#include <cmath>
#include <vector>
using namespace std;

// Prim算法适合稠密图，因为是站在点的角度上进行操作的，把点加进树，适合点少边多
// Kruskal算法适合稀疏图，因为是站在边的角度上进行操作的，把边加进树，适合点多边少

// Prim算法 184ms
class Solution {
   public:
    int minCostConnectPoints(vector<vector<int>> &points) {
        int n = points.size(), ans = 0;
        vector<vector<int>> g(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int dis = abs(points[i][0] - points[j][0]) +
                          abs(points[i][1] - points[j][1]);
                g[i][j] = dis;
                g[j][i] = dis;
            }
        }
        // 现有点到树中点最近距离 -1为已在树中
        vector<int> lowcost(n);
        // 将第一个点加进树中
        lowcost[0] = -1;
        for (int i = 1; i < n; ++i) {
            lowcost[i] = g[i][0];
        }
        // 还剩n - 1个点未加入
        for (int i = 1; i < n; ++i) {
            int minInd = 0, minDis = INT_MAX;
            for (int j = 0; j < n; ++j) {
                if (lowcost[j] == -1) continue;
                if (lowcost[j] < minDis) {
                    minInd = j;
                    minDis = lowcost[j];
                }
            }
            ans += minDis;
            lowcost[minInd] = -1;
            // 更新lowcost
            for (int j = 0; j < n; ++j) {
                if (lowcost[j] == -1) continue;
                lowcost[j] = min(lowcost[j], g[j][minInd]);
            }
        }
        return ans;
    }
};

// Kruskal算法 1236ms 103MB
class UnionFind {
   private:
    vector<int> fa;

   public:
    UnionFind(int n) : fa(n) {
        for (int i = 0; i < n; ++i) fa[i] = i;
    }

    int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

    int merge(int a, int b) {
        int ra = find(a), rb = find(b);
        if (ra == rb) return 0;
        fa[rb] = ra;
        return 1;
    }
};

class Solution2 {
   private:
    struct Edge {
        int from, to, dis;

        Edge(int f, int t, int d) : from(f), to(t), dis(d) {}

        bool operator<(const Edge &a) const { return dis < a.dis; }
    };

   public:
    int minCostConnectPoints(vector<vector<int>> &points) {
        int n = points.size();
        vector<Edge> edges;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int dis = abs(points[i][0] - points[j][0]) +
                          abs(points[i][1] - points[j][1]);
                edges.emplace_back(i, j, dis);
            }
        }
        sort(edges.begin(), edges.end());
        UnionFind uf(n);
        int ans = 0;
        for (auto &e : edges) {
            if (uf.merge(e.from, e.to)) ans += e.dis;
        }
        return ans;
    }
};