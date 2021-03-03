// LeetCode 304 二维区域和检索 - 矩阵不可变
#include <vector>
using namespace std;

// 一维前缀和数组累加 32ms
class NumMatrix {
   public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return;
        int m = matrix[0].size();
        pre_sum.resize(n, vector<int>(m + 1, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                pre_sum[i][j + 1] = pre_sum[i][j] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int i = row1; i <= row2; ++i) {
            sum += pre_sum[i][col2 + 1] - pre_sum[i][col1];
        }
        return sum;
    }

   private:
    vector<vector<int>> pre_sum;
};

// 二位前缀和 常数复杂度 pre_sum[i][j]代表以i,j为右下角0，0为左上角的元素之和

class NumMatrix2 {
   public:
    NumMatrix2(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return;
        int m = matrix[0].size();
        pre_sum.resize(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                pre_sum[i + 1][j + 1] = pre_sum[i + 1][j] + pre_sum[i][j + 1] -
                                        pre_sum[i][j] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return pre_sum[row2 + 1][col2 + 1] - pre_sum[row2 + 1][col1] -
               pre_sum[row1][col2 + 1] + pre_sum[row1][col1];
    }

   private:
    vector<vector<int>> pre_sum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */