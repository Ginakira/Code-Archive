// 每日一题 车的可用捕获量
#include <vector>
using namespace std;

class Solution {
   private:
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

   public:
    bool check_pos(int x, int y) { return x >= 0 && x < 8 && y >= 0 && y < 8; }

    int numRookCaptures(vector<vector<char>>& board) {
        int sx, sy, rows = 8, cols = 8;
        bool found = false;
        for (int i = 0; i < rows && !found; ++i) {
            for (int j = 0; j < cols && !found; ++j) {
                if (board[i][j] == 'R') {
                    sx = i, sy = j;
                    found = true;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < 4; ++i) {
            int tx = sx + dir[i][0], ty = sy + dir[i][1];
            while (check_pos(tx, ty) && board[tx][ty] == '.') {
                tx += dir[i][0], ty += dir[i][1];
            }
            if (check_pos(tx, ty) && board[tx][ty] == 'p') ans++;
        }
        return ans;
    }
};

class Solution2 {
   public:
    int numRookCaptures(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        int rook_x = 0, rook_y = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 'R') {
                    rook_x = i;
                    rook_y = j;
                    goto found;
                }
            }
        }
    found:
        auto attack = [&](int dx, int dy) {
            int x = rook_x + dx, y = rook_y + dy;
            while (x >= 0 && x < n && y >= 0 && y < m) {
                if (board[x][y] == 'p') {
                    return 1;
                } else if (board[x][y] == 'B') {
                    return 0;
                }
                x += dx;
                y += dy;
            }
            return 0;
        };
        return attack(0, -1) + attack(0, 1) + attack(-1, 0) + attack(1, 0);
    }
};