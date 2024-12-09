// LeetCode 1812 判断国际象棋棋盘中一个格子的颜色

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    bool squareIsWhite(string coordinates) {
        return (coordinates[0] - 'a' & 1) ? !(coordinates[1] - '1' & 1)
                                          : (coordinates[1] - '1' & 1);
    }
};

class Solution2 {
   public:
    bool squareIsWhite(string coordinates) {
        auto col = coordinates[0] - 'a', row = coordinates[1] - '1';
        int color = col & 1 ? 1 : 0;
        if (row & 1) {
            color = !color;
        }
        return color;
    }
};