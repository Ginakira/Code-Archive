// LeetCode 1091 二进制矩阵中的最短路径

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

class Solution {
   public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        constexpr array<tuple<int, int>, 8> dirs{{
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0},
            {1, 1},
            {1, -1},
            {-1, 1},
            {-1, -1},
        }};
        int n = grid.size(), m = grid[0].size();
        queue<tuple<int, int, int>> q;  // x, y, step
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        q.emplace(0, 0, 1);

        while (!q.empty()) {
            auto [x, y, step] = q.front();
            q.pop();
            if (grid[x][y] != 0 || vis[x][y]) {
                continue;
            }
            if (x == n - 1 && y == m - 1) {
                return step;
            }

            vis[x][y] = true;
            for (auto& dir : dirs) {
                auto [dx, dy] = dir;
                int tx = x + dx, ty = y + dy;
                if (tx >= 0 && tx < n && ty >= 0 && ty < n) {
                    q.emplace(tx, ty, step + 1);
                }
            }
        }
        return -1;
    }
};