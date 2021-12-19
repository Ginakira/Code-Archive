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
        int n = board.size();
        int m = board[0].size();
        int warship_count = 0;
        vector<vector<int>> seen(n, vector<int>(m, false));

        auto mark = [&](int x, int y, int dx, int dy) {
            int nx = x, ny = y;
            while (nx < n && ny < m && board[nx][ny] == 'X') {
                seen[nx][ny] = true;
                nx += dx, ny += dy;
            }
        };

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] != 'X' || seen[i][j]) continue;
                ++warship_count;
                mark(i, j, 0, 1);
                mark(i, j, 1, 0);
            }
        }

        return warship_count;
    }
};