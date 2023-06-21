// 面试题 16.19. 水域大小

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
   private:
    const int dirs[8][2]{
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1},
    };

    int dfs(vector<vector<int>>& land, int n, int m, int x, int y) {
        if (x < 0 || x >= n || y < 0 || y >= m || land[x][y] != 0) {
            return 0;
        }
        int area = 1;
        land[x][y] = -1;
        for (int i = 0; i < 8; ++i) {
            int tx = x + dirs[i][0], ty = y + dirs[i][1];
            area += dfs(land, n, m, tx, ty);
        }
        return area;
    }

   public:
    vector<int> pondSizes(vector<vector<int>>& land) {
        int n = land.size(), m = land[0].size();
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int area = 0;
                if (land[i][j] == 0) {
                    area += dfs(land, n, m, i, j);
                }
                if (area > 0) {
                    ans.emplace_back(area);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};