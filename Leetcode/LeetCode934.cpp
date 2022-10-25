// LeetCode 934 最短的桥

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int shortestBridge(vector<vector<int>> &grid) {
        int n = grid.size();
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        vector<pair<int, int>> island;
        queue<pair<int, int>> qu;

        for (int i = 0, flag = 1; i < n && flag; ++i) {
            for (int j = 0; j < n && flag; ++j) {
                if (grid[i][j] == 1) {
                    qu.emplace(i, j);
                    grid[i][j] = -1;
                    flag = 0;
                }
            }
        }
        while (!qu.empty()) {
            auto [i, j] = qu.front();
            island.emplace_back(i, j);
            qu.pop();
            for (auto &dir : dirs) {
                int tx = i + dir[0], ty = j + dir[1];
                if (tx < 0 || tx >= n || ty < 0 || ty >= n ||
                    grid[tx][ty] != 1) {
                    continue;
                }
                qu.emplace(tx, ty);
                grid[tx][ty] = -1;
            }
        }

        int step = 0;
        for (auto &&[i, j] : island) {
            qu.emplace(i, j);
        }

        while (!qu.empty()) {
            int qn = qu.size();
            for (int _ = 0; _ < qn; ++_) {
                auto [i, j] = qu.front();
                qu.pop();
                for (auto &dir : dirs) {
                    int tx = i + dir[0], ty = j + dir[1];
                    if (tx >= 0 && tx < n && ty >= 0 && ty < n) {
                        if (grid[tx][ty] == 0) {
                            qu.emplace(tx, ty);
                            grid[tx][ty] = -1;
                        } else if (grid[tx][ty] == 1) {
                            return step;
                        }
                    }
                }
            }
            ++step;
        }

        return step;
    }
};