// LeetCode 1970 你能穿过矩阵的最后一天

#include <algorithm>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   private:
    int n, m;
    const int dirs[4][2]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool check(int day, vector<vector<int>> &cells) {
        // 初始为全1 1代表可以走 0代表不可以走
        vector<vector<int>> grid(n, vector<int>(m, 1));
        for (int i = 0; i < day; ++i) {
            grid[cells[i][0] - 1][cells[i][1] - 1] = 0;
        }
        // BFS
        queue<tuple<int, int>> q;
        for (int j = 0; j < m; ++j) {
            if (grid[0][j]) {
                q.emplace(0, j);
                grid[0][j] = 0;
            }
        }

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if (x == n - 1) return true;
            for (auto &dir : dirs) {
                int tx = x + dir[0], ty = y + dir[1];
                if (tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
                if (!grid[tx][ty]) continue;
                q.emplace(tx, ty);
                grid[tx][ty] = 0;
            }
        }
        return false;
    }

   public:
    int latestDayToCross(int row, int col, vector<vector<int>> &cells) {
        n = row, m = col;
        int left = 0, right = cells.size(), mid;
        while (left < right) {
            mid = left + (right - left + 1) / 2;
            // 11111100000 找最后一个1
            if (check(mid, cells)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};