// LeetCode 474 一和零
#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;


// 思路相当于有两个容量的背包问题
class Solution {
   private:
    tuple<int, int> getZerosOnes(const string &str) {
        int zero_count = 0, one_count = 0;
        for (const char &c : str) {
            if (c == '0') {
                ++zero_count;
            } else {
                ++one_count;
            }
        }
        return make_tuple(zero_count, one_count);
    }

   public:
    int findMaxForm(vector<string> &strs, int m, int n) {
        int len = strs.size();
        // dp[i][j][k] 表示在前 i 个字符串中，使用 j 个 0 和 k 个 1
        // 的情况下最多可以得到的字符串数量
        vector<vector<vector<int>>> dp(
            len + 1, vector<vector<int>>(m + 1, vector<int>(n + 1)));
        for (int i = 1; i <= len; ++i) {
            auto [zeros, ones] = getZerosOnes(strs[i - 1]);
            for (int j = 0; j <= m; ++j) {
                for (int k = 0; k <= n; ++k) {
                    dp[i][j][k] = dp[i - 1][j][k];
                    if (zeros <= j && ones <= k) {
                        dp[i][j][k] = max(dp[i][j][k],
                                          dp[i - 1][j - zeros][k - ones] + 1);
                    }
                }
            }
        }
        return dp[len][m][n];
    }
};