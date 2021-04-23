// 剑指 Offer 04. 二维数组中的查找
#include <vector>
using namespace std;

// 杨氏矩阵
class Solution {
   public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int n = matrix.size(), m = matrix[0].size();
        int x = n - 1, y = 0;  // 从左下角出发
        while (x >= 0 && y < m) {
            if (target == matrix[x][y]) {
                return true;
            } else if (target < matrix[x][y]) {
                --x;
            } else {
                ++y;
            }
        }
        return false;
    }
};