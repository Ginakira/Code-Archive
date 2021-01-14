// LeetCode 463 岛屿的周长
#include <vector>
using namespace std;

// 模拟
class Solution {
   private:
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

   public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int ans = 0, rows = grid.size(), cols = grid[0].size();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 0) continue;
                ans += 4;
                for (int k = 0; k < 4; ++k) {
                    int dx = i + dir[k][0], dy = j + dir[k][1];
                    if (dx < 0 || dx >= rows || dy < 0 || dy >= cols ||
                        grid[dx][dy] == 0)
                        continue;
                    --ans;
                }
            }
        }
        return ans;
    }
};