// LeetCode 132 分割回文串II
#include <string>
#include <vector>
using namespace std;

// 回文预处理 + DP
class Solution {
   public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<int>> palindrome_mark(n, vector<int>(n, 1));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                palindrome_mark[i][j] =
                    (s[i] == s[j]) && palindrome_mark[i + 1][j - 1];
            }
        }

        vector<int> dp(n, INT_MAX);
        for (int i = 0; i < n; ++i) {
            if (palindrome_mark[0][i]) {
                dp[i] = 0;
                continue;
            }
            for (int j = 0; j < i; ++j) {
                if (palindrome_mark[j + 1][i]) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[n - 1];
    }
};