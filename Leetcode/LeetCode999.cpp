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