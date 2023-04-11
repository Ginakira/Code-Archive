// LeetCode 1041 困于环中的机器人

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
    bool isRobotBounded(string instructions) {
        std::array<std::array<int, 2>, 4> dirs{{
            {0, 1},  /* N */
            {1, 0},  /* E */
            {0, -1}, /* S */
            {-1, 0}, /* W */
        }};
        int cur_dir = 0;
        int x = 0, y = 0;
        for (auto &instruction : instructions) {
            if (instruction == 'G') {
                x += dirs[cur_dir][0];
                y += dirs[cur_dir][1];
            } else if (instruction == 'L') {
                cur_dir = (cur_dir + 3) % 4;
            } else {
                cur_dir = (cur_dir + 1) % 4;
            }
        }
        return cur_dir != 0 || (x == 0 && y == 0);
    }
};