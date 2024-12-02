// LeetCode 3274 检查棋盘方格颜色是否相同

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
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        auto get_color = [](const string& coord) -> int {
            auto col = coord[0] - 'a', row = coord[1] - '1';
            int color = col & 1 ? 0 : 1;
            if (row & 1) {
                color = !color;
            }
            return color;
        };
        return get_color(coordinate1) == get_color(coordinate2);
    }
};