// 每日一题 三维形体的表面积
#include <vector>
using namespace std;

// https://leetcode-cn.com/problems/surface-area-of-3d-shapes/solution/hua-tu-ji-suan-san-ge-zhong-die-bu-fen-by-liweiwei/
// 从垂直方向上看 对于每个单元格 垂直堆着的因覆盖减少的面个数是单元格高度 - 1
// 一行一行看 减少的面个数是相邻两个单元格高度的较小的一个
// 一列一列看同上
// 最终 用不考虑覆盖的总面积（6*个数）减去2 * 覆盖的面个数即为答案
class Solution {
   public:
    int surfaceArea(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int sum = 0;  // 总共立方体个数 用于计算不考虑覆盖的总面积
        int vertical_overlap = 0;  // 垂直堆放覆盖的面个数
        int row_overlap = 0;       // 行堆放覆盖的面个数
        int col_overlap = 0;       // 列堆放覆盖的面个数
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                sum += grid[i][j];
                if (grid[i][j] > 1) vertical_overlap += grid[i][j] - 1;
                if (j > 0) row_overlap += min(grid[i][j - 1], grid[i][j]);
                if (i > 0) col_overlap += min(grid[i - 1][j], grid[i][j]);
            }
        }
        return sum * 6 - (vertical_overlap + row_overlap + col_overlap) * 2;
    }
};