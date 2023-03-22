// LeetCode 1626 无矛盾的最佳球队

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<tuple<int, int>> members;
        members.reserve(n);
        for (int i = 0; i < n; ++i) {
            members.emplace_back(scores[i], ages[i]);
        }
        sort(members.begin(), members.end());

        int ans = 0;
        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i) {
            auto [score, age] = members[i];
            for (int j = i - 1; j >= 0; --j) {
                auto [score_j, age_j] = members[j];
                if (age_j <= age) {
                    dp[i] = max(dp[i], dp[j]);
                }
            }
            dp[i] += score;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};