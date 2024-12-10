// LeetCode 935 骑士拨号器

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
    int knightDialer(int n) {
        static constexpr int MOD = 1e9 + 7;
        std::array<std::vector<int>, 10> available_move = {{{4, 6},
                                                            {6, 8},
                                                            {7, 9},
                                                            {4, 8},
                                                            {3, 9, 0},
                                                            {},
                                                            {1, 7, 0},
                                                            {2, 6},
                                                            {1, 3},
                                                            {2, 4}}};
        vector<vector<int>> dp(2, vector<int>(10, 0));
        ranges::fill(dp[1], 1);
        for (int i = 2; i <= n; ++i) {
            int x = i & 1;
            for (int j = 0; j < 10; ++j) {
                dp[x][j] = 0;
                for (int k : available_move[j]) {
                    dp[x][j] = (dp[x][j] + dp[x ^ 1][k]) % MOD;
                }
            }
        }
        int ans = 0;
        for (auto x : dp[n & 1]) {
            ans = (ans + x) % MOD;
        }
        return ans;
    }
};