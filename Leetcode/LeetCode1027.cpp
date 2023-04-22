// LeetCode 1027 最长等差数列

#include <algorithm>
#include <array>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        constexpr int kMaxDiff = 500;
        // dp[i][j] 以nums[i]为结尾j为公差的数列长度
        // 公差范围为[-500,500]，避免负数下标所以统一加上500
        vector<vector<int>> dp(n, vector<int>(kMaxDiff * 2 + 1, 1));
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int d = nums[i] - nums[j] + kMaxDiff;
                dp[i][d] = max(dp[i][d], dp[j][d] + 1);
                ans = max(ans, dp[i][d]);
            }
        }
        return ans;
    }
};