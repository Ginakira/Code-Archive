// LeetCode 1928 规定时间内到达终点的最小花费

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int minCost(int maxTime, vector<vector<int>>& edges,
                vector<int>& passingFees) {
        constexpr int INF = 0x3f3f3f3f;
        int n = passingFees.size();
        vector<vector<int>> dp(
            maxTime + 1,
            vector<int>(n, INF));  // dp[i][j] 代表在时间i到达j的最小花费
        dp[0][0] = passingFees[0];

        for (int t = 1; t <= maxTime; ++t) {
            for (auto& edge : edges) {
                int u = edge[0], v = edge[1], cost = edge[2];
                if (cost <= t) {
                    dp[t][v] = min(dp[t][v], dp[t - cost][u] + passingFees[v]);
                    dp[t][u] = min(dp[t][u], dp[t - cost][v] + passingFees[u]);
                }
            }
        }

        int ans = INF;
        for (int i = 1; i <= maxTime; ++i) {
            ans = min(ans, dp[i][n - 1]);
        }
        return ans == INF ? -1 : ans;
    }
};