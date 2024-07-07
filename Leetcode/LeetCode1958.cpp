// LeetCode 1958 检查操作是否合法

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
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove,
                   char color) {
        static constexpr std::array<array<int, 2>, 8> dirs{{{0, 1},
                                                            {0, -1},
                                                            {1, 0},
                                                            {-1, 0},
                                                            {1, 1},
                                                            {1, -1},
                                                            {-1, 1},
                                                            {-1, -1}}};
        int n = board.size(), m = board[0].size();
        for (const auto& [dx, dy] : dirs) {
            int x = rMove + dx, y = cMove + dy;
            bool flag = false;
            int cnt = 1;
            while (x >= 0 && x < n && y >= 0 && y < m) {
                ++cnt;
                if (board[x][y] == '.') {
                    break;
                } else if (board[x][y] == color) {
                    flag = true;
                    break;
                }
                x += dx;
                y += dy;
            }
            if (flag && cnt >= 3) {
                return true;
            }
        }
        return false;
    }
};