// 每日一题 旋转矩阵
#include <vector>
using namespace std;

// 使用额外空间
class Solution {
   public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> ret = matrix;
        int row = matrix.size(), col = matrix[0].size();
        for (int i = 0; i < col; ++i) {
            for (int j = 0, k = row - 1; k >= 0; --k, ++j) {
                ret[i][j] = matrix[k][i];
            }
        }
        matrix = ret;
        return;
    }
};

// 对角线翻转 再水平翻转（以每一行中点为轴翻转）
class Solution2 {
   public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        int mid = n >> 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < mid; ++j) {
                swap(matrix[i][j], matrix[i][n - j - 1]);
            }
        }
    }
};