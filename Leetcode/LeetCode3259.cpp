// LeetCode 3259 超级饮料的最大强化能量

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
    long long maxEnergyBoost(vector<int>& energyDrinkA,
                             vector<int>& energyDrinkB) {
        int n = energyDrinkA.size();
        vector<array<long long, 2>> dp(n + 1, array<long long, 2>{0});
        dp[1][0] = energyDrinkA[0];
        dp[1][1] = energyDrinkB[0];
        for (int i = 2; i <= n; ++i) {
            dp[i][0] = max(dp[i - 1][0] + energyDrinkA[i - 1],
                           dp[i - 2][1] + energyDrinkA[i - 1]);
            dp[i][1] = max(dp[i - 1][1] + energyDrinkB[i - 1],
                           dp[i - 2][0] + energyDrinkB[i - 1]);
        }
        return max(dp[n][0], dp[n][1]);
    }
};
