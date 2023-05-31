// LeetCode 1130 叶值的最小代价生成树

#include <algorithm>
#include <array>
#include <limits>
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
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n,
                               vector<int>(n, numeric_limits<int>::max() / 4)),
            max_val(n, vector<int>(n));
        for (int j = 0; j < n; ++j) {
            max_val[j][j] = arr[j];
            dp[j][j] = 0;
            for (int i = j - 1; i >= 0; --i) {
                max_val[i][j] = max(arr[i], max_val[i + 1][j]);
                for (int k = i; k < j; ++k) {
                    dp[i][j] =
                        min(dp[i][j], dp[i][k] + dp[k + 1][j] +
                                          max_val[i][k] * max_val[k + 1][j]);
                }
            }
        }
        return dp[0][n - 1];
    }
};