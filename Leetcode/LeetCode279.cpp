// LeetCode 279 完全平方数
#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 思路同322
class Solution {
   public:
    int numSquares(int n) {
        vector<int> perfect_squares;
        for (int i = 1; i * i <= n; ++i) {
            perfect_squares.push_back(i * i);
        }
        vector<int> dp(n + 1, n);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (const int &squares : perfect_squares) {
                if (i >= squares) {
                    dp[i] = min(dp[i], dp[i - squares] + 1);
                }
            }
        }
        return dp[n];
    }
};