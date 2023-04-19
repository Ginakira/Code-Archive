// LeetCode 1043 分隔数组以达到最大和

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
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, 0);
        int cur_max = 0;
        for (int i = 0; i < n; ++i) {
            if (i < k) {
                cur_max = max(cur_max, arr[i]);
                dp[i] = cur_max * (i + 1);
                continue;
            }
            cur_max = 0;
            for (int j = i; j > i - k; --j) {
                // for (int j = i - k + 1; j <= i; ++j) {
                cur_max = max(cur_max, arr[j]);
                dp[i] = max(dp[i], dp[j - 1] + cur_max * (i - j + 1));
            }
        }
        return dp[n - 1];
    }
};