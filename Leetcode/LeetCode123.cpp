// LeetCode 123 买卖股票的最佳时机III
#include <vector>
using namespace std;

// 动态规划
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        /*
        buy1: 只进行过一次买操作；
        sell1: 进行了一次买操作和一次卖操作，即完成了一笔交易；
        buy2: 在完成了一笔交易的前提下，进行了第二次买操作；
        sell2: 完成了全部两笔交易。
        */
        int buy1 = -prices[0], sell1 = 0;
        int buy2 = -prices[0], sell2 = 0;
        for (int i = 1; i < n; ++i) {
            buy1 = max(buy1, -prices[i]);  // 什么也不做，或在今天第一次买
            sell1 =
                max(sell1, buy1 + prices[i]);  // 什么也不做，或在今天第一次卖
            buy2 = max(buy2,
                       sell1 - prices[i]);  // 什么也不做，或在今天进行第二次买
            sell2 = max(sell2,
                        buy2 + prices[i]);  // 什么也不做，或在今天进行第二次卖
        }
        return sell2;
    }
};