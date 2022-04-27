// LeetCode 417 太平洋大西洋水流问题

#include <algorithm>
#include <array>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   private:
    const array<array<int, 2>, 4> dirs{{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}};
    size_t n;
    size_t m;

    void bfs(const vector<vector<int>> &heights, vector<vector<bool>> &vis,
             int i, int j) {
        if (vis[i][j]) {
            return;
        }
        vis[i][j] = true;
        queue<tuple<int, int>> q;
        q.emplace(i, j);
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (auto &[dx, dy] : dirs) {
                int tx = x + dx, ty = y + dy;
                if (tx < 0 || tx >= n || ty < 0 || ty >= m || vis[tx][ty] ||
                    heights[tx][ty] < heights[x][y]) {
                    continue;
                }
                vis[tx][ty] = true;
                q.emplace(tx, ty);
            }
        }
    }

   public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
        n = heights.size();
        m = heights[0].size();
        vector<vector<bool>> pacific_vis(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic_vis(n, vector<bool>(m, false));

        for (int i = 0; i < n; ++i) {
            bfs(heights, pacific_vis, i, 0);
        }
        for (int j = 0; j < m; ++j) {
            bfs(heights, pacific_vis, 0, j);
        }
        for (int i = 0; i < n; ++i) {
            bfs(heights, atlantic_vis, i, m - 1);
        }
        for (int j = 0; j < m; ++j) {
            bfs(heights, atlantic_vis, n - 1, j);
        }

        vector<vector<int>> result;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (pacific_vis[i][j] && atlantic_vis[i][j]) {
                    result.emplace_back(vector<int>{i, j});
                }
            }
        }
        return result;
    }
};