// LeetCode 354 俄罗斯套娃信封问题
#include <vector>
using namespace std;

// 常规dp dp[i]就是以第i个信封作为最外层的答案
class Solution {
   public:
    int maxEnvelopes(vector<vector<int>> &envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](auto &a, auto &b) {
            return (a[0] == b[0] ? a[1] < b[1] : a[0] < b[0]);
        });
        vector<int> dp(n, 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (envelopes[i][0] > envelopes[j][0] &&
                    envelopes[i][1] > envelopes[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};