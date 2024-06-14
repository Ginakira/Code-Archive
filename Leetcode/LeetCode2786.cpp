// LeetCode 2786 访问数组中的位置使分数最大

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
    long long maxScore(vector<int>& nums, int x) {
        int n = nums.size();
        long long ans = nums[0];
        vector<long long> dp(2, std::numeric_limits<int>::min());
        dp[nums[0] % 2] = nums[0];
        for (int i = 1; i < n; ++i) {
            int parity = nums[i] % 2;
            long long cur =
                max(dp[parity] + nums[i], dp[1 - parity] - x + nums[i]);
            ans = max(ans, cur);
            dp[parity] = max(dp[parity], cur);
        }
        return ans;
    }
};