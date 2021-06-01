// LeetCode 1744. 你能在你最喜欢的那天吃到你最喜欢的糖果吗？
#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   private:
    typedef long long LL;

   public:
    vector<bool> canEat(vector<int>& candiesCount,
                        vector<vector<int>>& queries) {
        int n = candiesCount.size();
        vector<LL> pre_sum(n + 1);
        for (int i = 1; i <= n; ++i) {
            pre_sum[i] = pre_sum[i - 1] + candiesCount[i - 1];
        }
        vector<bool> ans;
        for (auto& query : queries) {
            int favorite_type = query[0], favorite_day = query[1],
                daily_cap = query[2];
            // 吃到该糖最晚的日期
            LL latest_day = pre_sum[favorite_type + 1] - 1;
            // 吃到该糖最早的日期
            LL earliest_day = pre_sum[favorite_type] / daily_cap;
            ans.emplace_back(
                (favorite_day <= latest_day && favorite_day >= earliest_day));
        }
        return ans;
    }
};