// LeetCode 343 整数拆分

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int integerBreak(int n) {
        // dp[i] 代表i将其拆分为至少两个正整数的和最大的乘积
        // 所以我们可以将i拆解为j和i-j
        // 那么dp[i]可以从两个状态转移过来
        // 1. j * (j - i) 即为j-i的部分不继续拆分
        // 2. j * dp[j - i] 即为j-i的部分继续拆分
        // 取最大值

        vector<int> dp(n + 1);
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
            }
        }
        return dp[n];
    }
};