// LeetCode 48 旋转图像
#include <vector>
using namespace std;

// 先转置（按对角线翻转） 再翻转每一行
class Solution {
   public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // Transpose matrix
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // Reverse rows
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n / 2; ++j) {
                swap(matrix[i][j], matrix[i][n - j - 1]);
            }
        }
        return;
    }
};