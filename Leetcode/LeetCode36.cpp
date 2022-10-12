// 有效的数独
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int x[9], y[9], z[9];  // 掩码 0可放 1不可放
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) x[i] = y[i] = z[i] = 0;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                int num = board[i][j] - '0';
                if (x[i] & (1 << num)) return false;
                if (y[j] & (1 << num)) return false;
                if (z[i / 3 * 3 + j / 3] & (1 << num)) return false;
                x[i] |= (1 << num);
                y[j] |= (1 << num);
                z[i / 3 * 3 + j / 3] |= (1 << num);
            }
        }
        return true;
    }
};

class Solution2 {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][10]{{false}};
        bool col[9][10]{{false}};
        bool box[9][10]{{false}};

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                int current = board[i][j] - '0';
                if (row[i][current]) return false;
                if (col[j][current]) return false;
                if (box[j / 3 + (i / 3) * 3][current]) return false;

                row[i][current] = true;
                col[j][current] = true;
                box[j / 3 + (i / 3 * 3)][current] = true;
            }
        }

        return true;
    }
};