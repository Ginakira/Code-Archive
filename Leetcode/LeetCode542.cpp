// 每日一题 01矩阵
#include <queue>
#include <vector>
using namespace std;

// 多源BFS
class Solution {
   private:
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    struct Node {
        int x, y, step;
    };

   public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        queue<Node> q;
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> ans(rows, vector<int>(cols, 0));
        vector<vector<bool>> vis(rows, vector<bool>(cols, 0));

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j]) continue;
                q.push({i, j, 0});
                vis[i][j] = true;
            }
        }

        Node temp;
        while (!q.empty()) {
            temp = q.front();
            q.pop();
            int x = temp.x, y = temp.y, step = temp.step;
            for (int i = 0; i < 4; ++i) {
                int tx = x + dir[i][0], ty = y + dir[i][1];
                if (tx < 0 || tx >= rows || ty < 0 || ty >= cols || vis[tx][ty])
                    continue;
                q.push({tx, ty, step + 1});
                ans[tx][ty] = step + 1;
                vis[tx][ty] = true;
            }
        }

        return ans;
    }
};