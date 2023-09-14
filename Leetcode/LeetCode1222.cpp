// LeetCode 1222 可以攻击国王的皇后

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
    vector<vector<int>> queensAttacktheKing(vector<vector<int>> &queens,
                                            vector<int> &king) {
        constexpr int n = 8;
        std::unordered_set<int> mark;
        for (auto &queen : queens) {
            mark.emplace(queen[0] * n + queen[1]);
        }
        constexpr std::array<std::array<int, 2>, 8> dirs{{{0, 1},
                                                          {0, -1},
                                                          {1, 0},
                                                          {-1, 0},
                                                          {1, 1},
                                                          {-1, -1},
                                                          {1, -1},
                                                          {-1, 1}}};

        vector<vector<int>> ans;
        for (auto [dx, dy] : dirs) {
            int x = king[0], y = king[1];
            while (x >= 0 && x < n && y >= 0 && y < n) {
                int id = x * n + y;
                if (mark.count(id)) {
                    ans.push_back({x, y});
                    break;
                }
                x += dx;
                y += dy;
            }
        }
        return ans;
    }
};
