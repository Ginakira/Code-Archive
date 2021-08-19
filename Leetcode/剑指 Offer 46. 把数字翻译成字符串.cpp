// 剑指 Offer 46. 把数字翻译成字符串

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// DP
class Solution {
   public:
    int translateNum(int num) {
        string s = to_string(num);
        int n = s.size();
        vector<int> dp(n + 1);
        dp[0] = 1, dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1];
            int pre = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
            if (pre >= 10 && pre <= 25) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
};

// 滚动数组优化
class Solution2 {
   public:
    int translateNum(int num) {
        string s = to_string(num);
        int n = s.size();
        int a = 1, b = 1, c = 1;
        for (int i = 2; i <= n; ++i) {
            c = b;
            int pre = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
            if (pre >= 10 && pre <= 25) {
                c += a;
            }
            a = b, b = c;
        }
        return c;
    }
};