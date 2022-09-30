// 面试题 01.08. 零矩阵

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> row_mark(n, false), col_mark(m, false);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == 0) {
                    row_mark[i] = true;
                    col_mark[j] = true;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (row_mark[i] || col_mark[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
        return;
    }
};