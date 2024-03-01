// LeetCode 2369 检查数组是否存在有效划分

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
   private:
    bool valid(int a, int b) { return a == b; }

    bool valid(int a, int b, int c) {
        return (a == b && a == c) || (a + 1 == b && b + 1 == c);
    }

   public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            if (i >= 2) {
                dp[i] = dp[i - 2] && valid(nums[i - 2], nums[i - 1]);
            }
            if (i >= 3) {
                dp[i] = dp[i] || (dp[i - 3] &&
                                  valid(nums[i - 3], nums[i - 2], nums[i - 1]));
            }
        }
        return dp[n];
    }
};