// LeetCode 2319 判断矩阵是否是一个X矩阵

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        bool flag = true;
        for (int i = 0; i < n && flag; ++i) {
            for (int j = 0; j < m && flag; ++j) {
                if (i == j || i + j + 1 == n) {
                    flag = grid[i][j] != 0;
                } else {
                    flag = grid[i][j] == 0;
                }
            }
        }
        return flag;
    }
};