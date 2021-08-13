// 剑指 Offer 14- I. 剪绳子

#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

// 同LC 343
class Solution {
   public:
    int cuttingRope(int n) {
        vector<int> dp(n + 1);
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
            }
        }
        return dp[n];
    }
};