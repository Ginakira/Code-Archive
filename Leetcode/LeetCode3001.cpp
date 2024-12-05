// LeetCode 3001 捕获黑皇后需要的最少移动次数

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
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        // 1. 车和皇后同一行，中间没有象
        if (a == e && (c != a || d < min(b, f) || d > max(b, f))) {
            return 1;
        }
        // 2. 车和皇后同一列，中间没有象
        if (b == f && (d != b || c < min(a, e) || c > max(a, e))) {
            return 1;
        }
        // 3. 象和皇后在同一对角线，中间没有车
        if (abs(c - e) == abs(d - f) &&
            ((c - e) * (b - f) != (a - e) * (d - f) || a < min(c, e) ||
             a > max(c, e))) {
            return 1;
        }
        // 4. 其他
        return 2;
    }
};