// LeetCode 650 只有两个键的键盘

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int minSteps(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 2; i <= n; ++i) {
            dp[i] = INT_MAX;
            for (int j = 1; j * j <= i; ++j) {
                if (i % j != 0) continue;
                dp[i] = min(dp[i], dp[j] + i / j);
                dp[i] = min(dp[i], dp[i / j] + j);
            }
        }
        return dp[n];
    }
};