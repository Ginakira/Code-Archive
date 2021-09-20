// LeetCode 673 最长递增子序列的个数

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n), cnt(n, 1);
        int max_len = 0, ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] >= nums[i]) continue;
                if (dp[j] + 1 == dp[i]) {
                    cnt[i] += cnt[j];
                } else if (dp[j] + 1 > dp[i]) {
                    cnt[i] = cnt[j];
                    dp[i] = dp[j] + 1;
                }
            }
            if (dp[i] > max_len) {
                max_len = dp[i];
                ans = cnt[i];
            } else if (dp[i] == max_len) {
                ans += cnt[i];
            }
        }
        return ans;
    }
};