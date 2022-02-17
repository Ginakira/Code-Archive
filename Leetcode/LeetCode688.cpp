// LeetCode 688 骑士在棋盘上的概率

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
    int dirs[8][2]{{-2, -1}, {-2, 1}, {2, -1}, {2, 1},
                   {-1, -2}, {-1, 2}, {1, -2}, {1, 2}};

   public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(
            k + 1, vector<vector<double>>(n + 1, vector<double>(n + 1)));
        for (int step = 0; step <= k; ++step) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (step == 0) {
                        dp[step][i][j] = 1;
                    } else {
                        for (auto &[dir_x, dir_y] : dirs) {
                            int nx = i + dir_x, ny = j + dir_y;
                            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                                dp[step][i][j] += dp[step - 1][nx][ny] / 8;
                            }
                        }
                    }
                }
            }
        }
        return dp[k][row][column];
    }
};