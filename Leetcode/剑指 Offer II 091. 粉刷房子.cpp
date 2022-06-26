// 剑指 Offer II 091. 粉刷房子

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int minCost(vector<vector<int>>& costs) {
        size_t n = costs.size();
        vector<vector<int>> dp(n, vector<int>(3));
        dp[0][0] = costs[0][0];
        dp[0][1] = costs[0][1];
        dp[0][2] = costs[0][2];

        for (size_t i = 1; i < n; ++i) {
            for (size_t j = 0; j < 3; ++j) {
                dp[i][j] = min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) +
                           costs[i][j];
            }
        }

        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};