// LeetCode 2304 网格中的最小路径代价

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
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(2, vector<int>(m, 0));
        dp[0] = grid[0];
        int cur = 0;
        for (int i = 1; i < n; ++i) {
            int next = !cur;
            for (int j = 0; j < m; ++j) {
                dp[next][j] = std::numeric_limits<int>::max();
                for (int k = 0; k < m; ++k) {
                    dp[next][j] = min(dp[next][j], dp[cur][k] + grid[i][j] + moveCost[grid[i - 1][k]][j]);
                }
            }
            cur = next;
        }
        return *min_element(dp[cur].begin(), dp[cur].end());
    }
};