// LeetCode 664 奇怪的打印机
#include <climits>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = n - 1; i >= 0; --i) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i][j - 1];
                } else {
                    int min_value = INT_MAX;
                    for (int k = i; k < j; ++k) {
                        min_value = min(min_value, dp[i][k] + dp[k + 1][j]);
                    }
                    dp[i][j] = min_value;
                }
            }
        }
        return dp[0][n - 1];
    }
};