// LeetCode 3033 修改矩阵

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
   public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        for (int j = 0; j < m; ++j) {
            int col_max = 0;
            for (int i = 0; i < n; ++i) {
                col_max = max(col_max, matrix[i][j]);
            }
            for (int i = 0; i < n; ++i) {
                if (matrix[i][j] == -1) {
                    matrix[i][j] = col_max;
                }
            }
        }
        return matrix;
    }
};