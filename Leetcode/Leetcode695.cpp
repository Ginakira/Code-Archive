// 每日一题 岛屿的最大面积
#include <vector>
using namespace std;

// 裸dfs
class Solution {
   private:
    int ans = 0, xn, yn;
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

   public:
    int dfs(int x, int y, vector<vector<int>>& grid) {
        int tx, ty, cnt = 1;
        grid[x][y] = 3;
        for (int i = 0; i < 4; ++i) {
            tx = x + dir[i][0], ty = y + dir[i][1];
            if (tx >= xn || ty >= yn || tx < 0 || ty < 0) continue;
            if (grid[tx][ty] == 1) {
                grid[tx][ty] = 3;
                cnt += dfs(tx, ty, grid);
            }
        }
        return cnt;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        xn = grid.size(), yn = grid[0].size();
        for (int i = 0; i < xn; ++i) {
            for (int j = 0; j < yn; ++j) {
                (grid[i][j] == 1) && (ans = max(dfs(i, j, grid), ans));
            }
        }
        return ans;
    }
};