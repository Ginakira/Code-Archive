// LeetCode 807 保持城市天际线

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int sum = 0;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int num = grid[i][j];
                int max_vertical = 0, max_horizontal = 0;
                for (int k = 0; k < n; ++k) {
                    max_vertical = max(max_vertical, grid[k][j]);
                }
                for (int k = 0; k < m; ++k) {
                    max_horizontal = max(max_horizontal, grid[i][k]);
                }
                sum += min(max_horizontal, max_vertical) - num;
            }
        }
        return sum;
    }
};