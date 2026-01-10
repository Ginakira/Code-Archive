// LeetCode 712 两个字符串的最小ASCII删除和

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
  int minimumDeleteSum(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; ++i) {
      dp[i][0] = dp[i - 1][0] + s1[i - 1];
    }
    for (int j = 1; j <= m; ++j) {
      dp[0][j] = dp[0][j - 1] + s2[j - 1];
    }
    for (int i = 1; i <= n; ++i) {
      char c1 = s1[i - 1];
      for (int j = 1; j <= m; ++j) {
        char c2 = s2[j - 1];
        if (c1 == c2) {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          dp[i][j] = min(dp[i - 1][j] + c1, dp[i][j - 1] + c2);
        }
      }
    }
    return dp[n][m];
  }
};