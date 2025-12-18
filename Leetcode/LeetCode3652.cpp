// LeetCode 3652 按策略买卖股票的最佳时机

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
  long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
    int n = prices.size();
    vector<long long> pre_sum(n + 1), pre_price(n + 1);
    for (int i = 0; i < n; ++i) {
      pre_sum[i + 1] = pre_sum[i] + prices[i] * strategy[i];
      pre_price[i + 1] = pre_price[i] + prices[i];
    }
    long long ans = pre_sum[n];
    for (int i = k; i <= n; ++i) {
      long long res = pre_sum[i - k] + pre_sum[n] - pre_sum[i] + pre_price[i] -
                      pre_price[i - k / 2];
      ans = max(ans, res);
    }
    return ans;
  }
};