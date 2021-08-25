// LeetCode 79 单词搜索

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   private:
    const int dirs[4][2]{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> vis;
    int n, m;

    bool dfs(vector<vector<char>> &board, string &word, int cur_index, int x,
             int y) {
        if (board[x][y] != word[cur_index]) return false;
        if (cur_index == word.size() - 1) return true;

        for (const auto &dir : dirs) {
            int tx = x + dir[0], ty = y + dir[1];
            if (tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
            if (vis[tx][ty]) continue;
            vis[tx][ty] = true;
            if (dfs(board, word, cur_index + 1, tx, ty)) {
                return true;
            }
            vis[tx][ty] = false;
        }
        return false;
    }

   public:
    bool exist(vector<vector<char>> &board, string word) {
        n = board.size(), m = board[0].size();
        vis.resize(n, vector<int>(m, false));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                vis[i][j] = true;
                if (dfs(board, word, 0, i, j)) {
                    return true;
                }
                vis[i][j] = false;
            }
        }
        return false;
    }
};