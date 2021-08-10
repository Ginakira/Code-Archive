// 每日一题 01矩阵
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

// 多源BFS
class Solution {
   public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> result(n, vector<int>(m, 0));
        vector<vector<int>> seen(n, vector<int>(m, 0));
        queue<tuple<int, int, int>> q;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 0) {
                    q.emplace(i, j, 0);
                    seen[i][j] = true;
                }
            }
        }

        while (!q.empty()) {
            auto [x, y, step] = q.front();
            q.pop();
            for (auto& dir : dirs) {
                int tx = x + dir[0], ty = y + dir[1];
                if (tx < 0 || tx >= n || ty < 0 || ty >= m || seen[tx][ty]) {
                    continue;
                }
                q.emplace(tx, ty, step + 1);
                result[tx][ty] = step + 1;
                seen[tx][ty] = true;
            }
        }
        return result;
    }
};