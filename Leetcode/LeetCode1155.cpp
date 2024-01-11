// LeetCode 1155 掷骰子等于目标和的方法数

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
   private:
    static constexpr int MOD = 1000000007;

   public:
    int numRollsToTarget(int n, int k, int target) {
        vector<int> dp(target + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = target; j >= i - 1; --j) {
                dp[j] = 0;
                for (int x = 1; x <= k; ++x) {
                    if (j - x < 0) {
                        continue;
                    }
                    dp[j] = (dp[j] + dp[j - x]) % MOD;
                }
            }
        }
        return dp[target];
    }
};