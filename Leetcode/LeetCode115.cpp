// LeetCode 115 不同的子序列
#include <string>
#include <vector>
using namespace std;

// DP
// 状态定义：dp[i][j] 为s串前i个字符中的子序列中t串前j个字符的出现个数
// 状态转移：
// 1. 当前位置母串子串的字符不同：dp[i][j]=dp[i-1][j]
// 答案为在s串前i-1个中找t串前j个字符出现次数
// 2. 当前位置母串子串的字符相同：dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
// 答案为在s串前i-1个中找t串前j个字符出现次数+在s串前i-1个中找t串前j-1个字符出现次数
class Solution {
   public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (j > i) break;
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return (int)dp[n][m];
    }
};