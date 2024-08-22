// LeetCode 3148 矩阵中的最大得分

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
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = numeric_limits<int>::min();
        vector<vector<int>> f(n + 1,
                              vector<int>(m + 1, numeric_limits<int>::max()));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                int min_val = min(f[i][j - 1], f[i - 1][j]);
                ans = max(ans, grid[i - 1][j - 1] - min_val);
                f[i][j] = min(min_val, grid[i - 1][j - 1]);
            }
        }
        return ans;
    }
};