// LeetCode 309 买卖股票的最佳时机含冷冻期

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
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        int n = prices.size();
        // f0 -> f[i][0] 当前持有股票的累计最大收益
        // f1 -> f[i][1] 当前不持有股票并处于冷冻期的累计最大收益
        // f2 -> f[i][2] 当前不持有股票并不在冷冻期的累计最大收益
        int f0 = -prices[0], f1 = 0, f2 = 0;
        for (int i = 1; i < n; ++i) {
            int new_f0 = max(f0, f2 - prices[i]);
            int new_f1 = f0 + prices[i];
            int new_f2 = max(f1, f2);
            f0 = new_f0, f1 = new_f1, f2 = new_f2;
        }
        return max(f1, f2);
    }
};