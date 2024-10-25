// LeetCode 3180 执行操作可获得的最大总奖励I

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
    int maxTotalReward(vector<int>& rewardValues) {
        int n = rewardValues.size();
        ranges::sort(rewardValues);
        vector<vector<bool>> dp(n + 1,
                                vector<bool>(rewardValues.back() * 2, false));
        int ans = 0;
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i) {
            int reward = rewardValues[i - 1];
            for (int j = 0; j < reward * 2; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (j >= reward && dp[i - 1][j - reward]) {
                    dp[i][j] = true;
                }
                if (i == n && dp[i][j]) {
                    ans = max(ans, j);
                }
            }
        }
        return ans;
    }
};
