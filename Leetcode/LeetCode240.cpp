// LeetCode 240 搜索二维矩阵II
#include <vector>
using namespace std;

// 同LCOF04
class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        int row = rows - 1, col = 0;
        while (row >= 0 && col < cols) {
            if (matrix[row][col] < target) {
                ++col;
            } else if (matrix[row][col] > target) {
                --row;
            } else {
                return true;
            }
        }
        return false;
    }
};