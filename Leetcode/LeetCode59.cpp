// LeetCode 59 螺旋矩阵II
#include <vector>
using namespace std;

// 与LC54思路一致
class Solution {
   public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n, -1));
        int current = 1;
        int up = 0, down = n - 1, left = 0, right = n - 1;
        while (true) {
            for (int i = left; i <= right; ++i) ret[up][i] = current++;
            if (++up > down) break;
            for (int i = up; i <= down; ++i) ret[i][right] = current++;
            if (--right < left) break;
            for (int i = right; i >= left; --i) ret[down][i] = current++;
            if (--down < up) break;
            for (int i = down; i >= up; --i) ret[i][left] = current++;
            if (++left > right) break;
        }
        return ret;
    }
};