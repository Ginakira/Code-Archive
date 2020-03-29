// 每日一题 地图分析
#include <queue>
#include <vector>
using namespace std;

// 解法1:以陆地为中心的BFS
// 将所有陆地入队
class Solution {
   private:
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    struct node {
        int x, y;
    };

   public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<node> q;
        int rows = grid.size(), cols = grid[0].size();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) q.push({i, j});
            }
        }
        bool hasOcean = false;
        struct node tmp;
        while (!q.empty()) {
            tmp = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int tx = tmp.x + dir[i][0], ty = tmp.y + dir[i][1];
                if (tx < 0 || tx >= rows || ty < 0 || ty >= cols ||
                    grid[tx][ty] != 0) {
                    continue;
                }
                hasOcean = true;
                q.push({tx, ty});
                grid[tx][ty] = grid[tmp.x][tmp.y] + 1;
            }
        }
        if (!hasOcean) return -1;
        return grid[tmp.x][tmp.y] - 1;
    }
};