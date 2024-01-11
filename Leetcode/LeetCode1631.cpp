// LeetCode 1631 最小体力消耗路径
#include <algorithm>
#include <vector>
using namespace std;

// 并查集优先合并权值小的边，如果起点终点连通则停止
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


// BFS + 二分剪枝
class Solution2 {
   private:
    constexpr static std::array<std::array<int, 2>, 4> dirs{{
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0},
    }};

   public:
    int minimumEffortPath(vector<vector<int>> &heights) {
        int n = heights.size();
        int m = heights[0].size();
        int left = 0, right = 1e6 - 1, ans = 0;
        while (left <= right) {
            queue<pair<int, int>> q;
            vector<bool> seen(n * m, false);
            int mid = (left + right) / 2;
            q.emplace(0, 0);
            seen[0] = true;
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                for (auto [dx, dy] : dirs) {
                    int nx = x + dx, ny = y + dy;
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m ||
                        seen[nx * m + ny]) {
                        continue;
                    }
                    if (abs(heights[x][y] - heights[nx][ny]) > mid) {
                        continue;
                    }
                    seen[nx * m + ny] = true;
                    q.emplace(nx, ny);
                }
            }
            if (seen[n * m - 1]) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
