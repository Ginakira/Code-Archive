// LeetCode 552 学生出勤记录II

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   private:
    static constexpr int MOD = 1e9 + 7;

   public:
    int checkRecord(int n) {
        // dp[i][j][k] 在第i天已经缺席了j次且末尾有k次连续的迟到
        // 可获得奖励的记录情况
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        dp[0][0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            // 当日记录是A
            for (int k = 0; k < 3; ++k) {
                dp[i][1][0] = (dp[i][1][0] + dp[i - 1][0][k]) % MOD;
            }
            // 当日记录是L
            for (int j = 0; j < 2; ++j) {
                for (int k = 1; k < 3; ++k) {
                    dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k - 1]) % MOD;
                }
            }
            // 当日记录是P
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 3; ++k) {
                    dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j][k]) % MOD;
                }
            }
        }
        int sum = 0;
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 3; ++k) {
                sum = (sum + dp[n][j][k]) % MOD;
            }
        }
        return sum;
    }
};