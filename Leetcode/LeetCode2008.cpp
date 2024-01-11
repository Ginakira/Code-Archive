// LeetCode 2008 出租车的最大盈利

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
    long long maxTaxiEarnings(int n, vector<vector<int>> &rides) {
        sort(rides.begin(), rides.end(),
             [](const auto &a, const auto &b) { return a[1] < b[1]; });
        int m = rides.size();
        vector<long long> dp(m + 1);
        for (int i = 0; i < m; ++i) {
            int pre = upper_bound(rides.begin(), rides.begin() + i, rides[i][0],
                                  [](int val, const auto &ride) {
                                      return val < ride[1];
                                  }) -
                      rides.begin();
            dp[i + 1] =
                max(dp[i], dp[pre] + rides[i][1] - rides[i][0] + rides[i][2]);
        }
        return dp[m];
    }
};
