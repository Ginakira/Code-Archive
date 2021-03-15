// LeetCode 54 螺旋矩阵
#include <vector>
using namespace std;

// 每次遍历一圈 同时更新四个角的边界
class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int up = 0, down = n - 1, left = 0, right = m - 1;
        vector<int> ret;
        while (true) {
            for (int i = left; i <= right; ++i) ret.emplace_back(matrix[up][i]);
            if (++up > down) break;
            for (int i = up; i <= down; ++i) ret.emplace_back(matrix[i][right]);
            if (--right < left) break;
            for (int i = right; i >= left; --i)
                ret.emplace_back(matrix[down][i]);
            if (--down < up) break;
            for (int i = down; i >= up; --i) ret.emplace_back(matrix[i][left]);
            if (++left > right) break;
        }
        return ret;
    }
};