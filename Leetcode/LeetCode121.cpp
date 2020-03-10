// 每日一题 买卖股票的最佳时机
#include <vector>
using namespace std;

// 暴力枚举 1772ms
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, n = prices.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ans = max(ans, prices[j] - prices[i]);
            }
        }
        return ans;
    }
};

// 一遍扫描 4ms
class Solution2 {
   public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, min_val = 0x3f3f3f3f, n = prices.size();
        for (int i = 0; i < n; ++i) {
            if (prices[i] < min_val) {
                min_val = prices[i];
            } else {
                ans = max(ans, prices[i] - min_val);
            }
        }
        return ans;
    }
};