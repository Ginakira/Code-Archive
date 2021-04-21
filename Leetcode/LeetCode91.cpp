// LeetCode 91 解码方法
#include <string>
#include <vector>
using namespace std;

// dp[i]为在s中取前i个字符传的解码方法总数
// 对于字符串中的每一位，我们可以采用两种解码操作：
// 1. 将这一位视为单独的一位解码
// 2. 将这一位和这一位的前一位一起解码
// 如果操作一合法（即当前位不是0），那么dp[i]需要加上dp[i-1]的方案数
// 操作二同理，方案数需累加
class Solution {
   public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }
            if (i > 1 && s[i - 2] != '0' &&
                ((s[i - 2] - '0') * 10 + s[i - 1] - '0') <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
};
