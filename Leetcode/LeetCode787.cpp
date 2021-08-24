// LeetCode 787 K站中转内最便宜的航班

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        constexpr int INF = 0x3f3f3f3f;
        vector<vector<int>> dp(
            k + 2,
            vector<int>(n, INF));  // dp[i][j]代表搭乘i次航班到达地点j的最小花费
        dp[0][src] = 0;
        for (int i = 1; i <= k + 1; ++i) {
            for (auto& flight : flights) {
                int from = flight[0], to = flight[1], price = flight[2];
                dp[i][to] = min(dp[i][to], dp[i - 1][from] + price);
            }
        }

        int ans = INF;
        for (int i = 1; i <= k + 1; ++i) {
            ans = min(ans, dp[i][dst]);
        }
        return ans == INF ? -1 : ans;
    }
};