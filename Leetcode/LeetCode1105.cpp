// LeetCode 1105 填充书架

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
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n + 1, 1000000);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            int max_height = 0, cur_width = 0;
            for (int j = i - 1; j >= 0; --j) {
                cur_width += books[j][0];
                if (cur_width > shelfWidth) {
                    break;
                }
                max_height = max(max_height, books[j][1]);
                dp[i] = min(dp[i], dp[j] + max_height);
            }
        }
        return dp[n];
    }
};