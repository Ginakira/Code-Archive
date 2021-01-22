// 剑指 Offer 04. 二维数组中的查找
#include <vector>
using namespace std;

// 根据有序的性质，从左下角或者右上角开始找，斜过来看就像是二叉排序树
class Solution {
   public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        int n = matrix.size(), m = matrix[0].size();
        for (int i = 0, j = m - 1; i >= 0 && j >= 0 && i < n && j < m;) {
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] < target) {
                ++i;
            } else {
                --j;
            }
        }
        return false;
    }
};