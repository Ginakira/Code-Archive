// LeetCode 1599 经营摩天轮的最大利润

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost,
                               int runningCost) {
        int i = 0, n = customers.size();
        int ans = -1, max_profit = 0, current_profit = 0;
        int waiting = 0;
        while (waiting > 0 || i < n) {
            waiting += i < n ? customers[i] : 0;
            int boarding = min(4, waiting);
            waiting -= boarding;
            current_profit += boarding * boardingCost - runningCost;
            ++i;
            if (current_profit > max_profit) {
                max_profit = current_profit;
                ans = i;
            }
        }
        return ans;
    }
};
