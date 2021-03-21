// LeetCode 73 矩阵置零
#include <vector>
using namespace std;

// 使用第一行和第一列的元素进行标记，该行/该列是否需要被置零
class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        bool row_zero = false, col_zero = false;
        for (int i = 0; i < n; ++i) {
            if (!matrix[i][0]) {
                col_zero = true;
                break;
            }
        }
        for (int j = 0; j < m; ++j) {
            if (!matrix[0][j]) {
                row_zero = true;
                break;
            }
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (!matrix[i][j]) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (!matrix[i][0] || !matrix[0][j]) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (col_zero) {
            for (int i = 0; i < n; ++i) {
                matrix[i][0] = 0;
            }
        }
        if (row_zero) {
            for (int j = 0; j < m; ++j) {
                matrix[0][j] = 0;
            }
        }
        return;
    }
};