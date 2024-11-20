// LeetCode 3248 矩阵中的蛇

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
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int i = 0, j = 0;
        static unordered_map<string, tuple<int, int>> mp{{"UP", {-1, 0}},
                                                         {"RIGHT", {0, 1}},
                                                         {"DOWN", {1, 0}},
                                                         {"LEFT", {0, -1}}};
        for (const auto& cmd : commands) {
            int ti, tj;
            tie(ti, tj) = mp[cmd];
            i += ti;
            j += tj;
        }
        return i * n + j;
    }
};