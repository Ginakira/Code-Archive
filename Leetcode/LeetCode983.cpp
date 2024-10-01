// LeetCode 983 最低票价

#include <algorithm>
#include <array>
#include <cmath>
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
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(366, 0);
        for (int i = 1, j = 0; i <= 365 && j < n; ++i) {
            if (i != days[j]) {
                dp[i] = dp[i - 1];
                continue;
            }
            dp[i] = min({
                dp[max(i - 1, 0)] + costs[0],
                dp[max(i - 7, 0)] + costs[1],
                dp[max(i - 30, 0)] + costs[2],
            });
            ++j;
        }
        return dp[days.back()];
    }
};