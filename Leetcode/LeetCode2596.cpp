// LeetCode 2586 检查骑士巡视方案

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
    bool checkValidGrid(vector<vector<int>>& grid) {
        if (grid[0][0] != 0) {
            return false;
        }
        int n = grid.size();
        vector<tuple<int, int>> pos(n * n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                pos[grid[i][j]] = make_tuple(i, j);
            }
        }
        for (int i = 1; i < n * n; ++i) {
            auto [last_x, last_y] = pos[i - 1];
            auto [x, y] = pos[i];
            if (abs(x - last_x) * abs(y - last_y) != 2) {
                return false;
            }
        }
        return true;
    }
};