// LeetCode 1475 商品折扣后的最终价格

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> finalPrices(vector<int>& prices) {
        for (int i = 0; i < prices.size(); ++i) {
            int discount = 0;
            for (int j = i + 1; j < prices.size(); ++j) {
                if (prices[j] <= prices[i]) {
                    discount = prices[j];
                    break;
                }
            }
            prices[i] -= discount;
        }
        return prices;
    }
};