// 剑指 Offer 29. 顺时针打印矩阵

#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return {};
        int n = matrix.size(), m = matrix[0].size();
        int up = 0, down = n - 1, left = 0, right = m - 1;
        vector<int> result;
        while (true) {
            for (int l = left; l <= right; ++l) {
                result.push_back(matrix[up][l]);
            }
            if (++up > down) break;
            for (int u = up; u <= down; ++u) {
                result.push_back(matrix[u][right]);
            }
            if (--right < left) break;
            for (int r = right; r >= left; --r) {
                result.push_back(matrix[down][r]);
            }
            if (--down < up) break;
            for (int d = down; d >= up; --d) {
                result.push_back(matrix[d][left]);
            }
            if (++left > right) break;
        }
        return result;
    }
};