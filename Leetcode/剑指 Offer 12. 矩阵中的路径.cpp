// 剑指 Offer 12. 矩阵中的路径
#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   private:
    int rows, cols;
    const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> seen;

    bool dfs(vector<vector<char>> &board, string &word, int x, int y,
             int current_index) {
        if (x < 0 || x >= rows || y < 0 || y >= cols || seen[x][y] ||
            board[x][y] != word[current_index]) {
            return false;
        }
        if (current_index == word.size() - 1) {
            return true;
        }
        seen[x][y] = true;
        for (int k = 0; k < 4; ++k) {
            int nx = x + dir[k][0], ny = y + dir[k][1];
            if (dfs(board, word, nx, ny, current_index + 1)) {
                return true;
            }
        }
        seen[x][y] = false;
        return false;
    }

   public:
    bool exist(vector<vector<char>> &board, string word) {
        rows = board.size(), cols = board[0].size();
        seen.resize(rows, vector<int>(cols));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};