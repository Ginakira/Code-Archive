// LeetCode 823 带因子的二叉树

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
    int numFactoredBinaryTrees(vector<int>& arr) {
        constexpr int MOD = 1e9 + 7;
        int n = arr.size();
        std::sort(arr.begin(), arr.end());
        vector<uint64_t> dp(n);
        uint64_t ans = 0;
        for (int i = 0; i < n; ++i) {
            dp[i] = 1;
            for (int l = 0, r = i - 1; l <= r; ++l) {
                while (r >= l && 1LL * arr[l] * arr[r] > arr[i]) {
                    --r;
                }
                if (l <= r && 1LL * arr[l] * arr[r] == arr[i]) {
                    if (l == r) {
                        dp[i] = (dp[i] + dp[l] * dp[r]) % MOD;
                    } else {
                        dp[i] = (dp[i] + dp[l] * dp[r] * 2) % MOD;
                    }
                }
            }
            ans = (ans + dp[i]) % MOD;
        }
        return ans;
    }
};
