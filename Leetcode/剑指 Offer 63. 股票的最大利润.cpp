// 剑指 Offer 63. 股票的最大利润

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, min_price = INT_MAX;
        for (int price : prices) {
            min_price = min(min_price, price);
            ans = max(ans, price - min_price);
        }
        return ans;
    }
};