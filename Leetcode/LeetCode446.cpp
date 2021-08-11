// LeetCode 446 等差数列划分II - 子序列

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<long long, int>> dp(n);
        // dp[i][j]
        // 代表以nums[i]为结尾，j为公差的弱等差数列的数量（长度大于等于2的等差数列数量）
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long long d = (long long)nums[i] - nums[j];
                auto it = dp[j].find(d);
                int cnt = (it == dp[j].end() ? 0 : it->second);
                ans += cnt;
                dp[i][d] += cnt + 1;
            }
        }
        return ans;
    }
};