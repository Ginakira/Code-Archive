// LeetCode 419 甲板上的战舰
#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int countBattleships(vector<vector<char>>& board) {
        int cnt = 0;
        int n = board.size();
        int m = board[0].size();
        function<void(int, int)> helper = [&](int i, int j) {
            static constexpr array<array<int, 2>, 2> dirs{{{1, 0}, {0, 1}}};
            for (auto& [dx, dy] : dirs) {
                int nx = i + dx, ny = j + dy;
                if (nx >= n || ny >= m || board[nx][ny] != 'X') {
                    continue;
                }
                board[nx][ny] = '.';
                helper(nx, ny);
            }
        };
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 'X') {
                    ++cnt;
                    helper(i, j);
                }
            }
        }
        return cnt;
    }
};

class Solution2 {
   public:
    int countBattleships(vector<vector<char>>& board) {
        int cnt = 0;
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] != 'X') {
                    continue;
                }
                if (i > 0 && board[i - 1][j] == 'X') {
                    continue;
                }
                if (j > 0 && board[i][j - 1] == 'X') {
                    continue;
                }
                ++cnt;
            }
        }
        return cnt;
    }
};