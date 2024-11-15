// LeetCode 3239 最少翻转次数使二进制矩阵回文 I

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
    int minFlips(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int row_cnt = 0, col_cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int l = 0, r = m - 1; l < r; ++l, --r) {
                if (grid[i][l] != grid[i][r]) {
                    ++row_cnt;
                }
            }
        }
        for (int j = 0; j < m; ++j) {
            for (int l = 0, r = n - 1; l < r; ++l, --r) {
                if (grid[l][j] != grid[r][j]) {
                    ++col_cnt;
                }
            }
        }
        return min(row_cnt, col_cnt);
    }
};