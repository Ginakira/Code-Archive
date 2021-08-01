// LeetCode 73 矩阵置零
#include <set>
#include <vector>
using namespace std;

// 使用第一行和第一列的元素进行标记，该行/该列是否需要被置零
class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        // 使用第一行第一列标记此行此列是否需要置零
        bool row_zero = false,
             col_zero = false;  // 第一行和第一列本身是否需要置零

        for (int i = 0; i < n; ++i) {
            if (matrix[i][0] == 0) {
                col_zero = true;
                break;
            }
        }
        for (int j = 0; j < m; ++j) {
            if (matrix[0][j] == 0) {
                row_zero = true;
                break;
            }
        }

        // 使用第一行和第一列记录是否置零
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        // 使用记录置零
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        // 处理首行首列
        if (row_zero) {
            for (int j = 0; j < m; ++j) {
                matrix[0][j] = 0;
            }
        }
        if (col_zero) {
            for (int i = 0; i < n; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};

// set记录
class Solution2 {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        set<pair<int, int>> st;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == 0) {
                    st.insert(pair<int, int>{i, j});
                }
            }
        }

        for (auto& pr : st) {
            auto& [r, c] = pr;
            for (int i = 0; i < n; ++i) {
                matrix[i][c] = 0;
            }
            for (int j = 0; j < m; ++j) {
                matrix[r][j] = 0;
            }
        }
    }
};