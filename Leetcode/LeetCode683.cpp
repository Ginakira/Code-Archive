// LeetCOde 683 三维形体投影面积

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int vertical_view = 0, front_view = 0,
            end_view = 0;  // 俯视图 正视图 侧视图
        for (int i = 0; i < n; ++i) {
            int row_max = 0;
            for (int j = 0; j < m; ++j) {
                row_max = max(row_max, grid[i][j]);
                if (grid[i][j]) {
                    ++vertical_view;
                }
            }
            end_view += row_max;
        }
        for (int j = 0; j < m; ++j) {
            int col_max = 0;
            for (int i = 0; i < n; ++i) {
                col_max = max(col_max, grid[i][j]);
            }
            front_view += col_max;
        }
        return vertical_view + front_view + end_view;
    }
};