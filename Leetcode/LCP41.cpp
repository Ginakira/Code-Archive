// LCP 41 黑白翻转棋

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
   private:
    const int dirs[8][2]{{1, 0}, {-1, 0}, {0, 1},  {0, -1},
                         {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

    bool judge(const vector<string>& chessboard, int x, int y, int dx, int dy) {
        int tx = x + dx, ty = y + dy;
        while (tx >= 0 && tx < chessboard.size() && ty >= 0 &&
               ty < chessboard[0].size()) {
            if (chessboard[tx][ty] == 'X') {
                return true;
            } else if (chessboard[tx][ty] == '.') {
                return false;
            }
            tx += dx;
            ty += dy;
        }
        return false;
    }

    int bfs(vector<string> chessboard, int px, int py) {
        int cnt = 0;
        queue<tuple<int, int>> q;
        q.emplace(px, py);
        chessboard[px][py] = 'X';
        while (!q.empty()) {
            auto [tx, ty] = q.front();
            q.pop();
            for (int i = 0; i < 8; ++i) {
                if (judge(chessboard, tx, ty, dirs[i][0], dirs[i][1])) {
                    int x = tx + dirs[i][0], y = ty + dirs[i][1];
                    while (chessboard[x][y] != 'X') {
                        q.emplace(x, y);
                        chessboard[x][y] = 'X';
                        x += dirs[i][0];
                        y += dirs[i][1];
                        ++cnt;
                    }
                }
            }
        }
        return cnt;
    }

   public:
    int flipChess(vector<string>& chessboard) {
        int ans = 0;
        int n = chessboard.size(), m = chessboard[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (chessboard[i][j] == '.') {
                    ans = max(ans, bfs(chessboard, i, j));
                }
            }
        }
        return ans;
    }
};