// LeetCode 1380 矩阵中的幸运数

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> row_min(n, INT_MAX);
        vector<int> col_max(m, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                row_min[i] = min(row_min[i], matrix[i][j]);
                col_max[j] = max(col_max[j], matrix[i][j]);
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (row_min[i] == col_max[j]) {
                    ans.emplace_back(row_min[i]);
                    break;
                }
            }
        }
        return ans;
    }
};