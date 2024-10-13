// LeetCode 1884 鸡蛋掉落-两枚鸡蛋

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
    int twoEggDrop(int n) {
        vector<int> dp(n + 1, numeric_limits<int>::max() / 2);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int k = 1; k <= i; ++k) {
                dp[i] = min(dp[i], max(k - 1, dp[i - k]) + 1);
            }
        }
        return dp[n];
    }
};