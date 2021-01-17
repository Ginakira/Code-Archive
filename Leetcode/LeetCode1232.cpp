// LeetCode 1232 缀点成线
#include <vector>
using namespace std;

class Solution {
   public:
    // 检查斜率是否一致即可
    // (y2 - y1) / (x2 - x1) == (y3 - y2) / (x3 - x2)
    // 由于精度损失，所以转换为乘法 (x2 - x1) * (y3 - y2) == (y2 - y1) * (x3 -
    // x2)
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        for (int i = 2; i < n; ++i) {
            auto &a = coordinates[i - 2], &b = coordinates[i - 1],
                 &c = coordinates[i];
            if ((b[0] - a[0]) * (c[1] - b[1]) !=
                (b[1] - a[1]) * (c[0] - b[0])) {
                return false;
            }
        }
        return true;
    }
};