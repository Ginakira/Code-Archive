// LeetCode 1801 积压订单中的订单总数

#include <algorithm>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    using PII = pair<int, int>;
    int getNumberOfBacklogOrders(vector<vector<int>> &orders) {
        constexpr int MOD = 1e9 + 7;
        priority_queue<PII> buy;
        priority_queue<PII, vector<PII>, greater<PII>> sell;

        auto func = [&](auto &qa, auto &qb, int price, int amount, auto &&op) {
            while (amount > 0 && !qa.empty() && op(qa.top().first, price)) {
                auto [qa_price, qa_cnt] = qa.top();
                qa.pop();
                auto cnt = min(qa_cnt, amount);
                qa_cnt -= cnt;
                amount -= cnt;
                if (qa_cnt > 0) {
                    qa.emplace(qa_price, qa_cnt);
                }
            }
            if (amount > 0) {
                qb.emplace(price, amount);
            }
        };

        for (auto &order : orders) {
            int price = order[0], amount = order[1], type = order[2];
            if (type == 0) {
                func(sell, buy, price, amount, less_equal{});
            } else {
                func(buy, sell, price, amount, greater_equal{});
            }
        }

        int sum = 0;
        while (!sell.empty()) {
            auto [_, cnt] = sell.top();
            sell.pop();
            sum = (sum + cnt) % MOD;
        }
        while (!buy.empty()) {
            auto [_, cnt] = buy.top();
            buy.pop();
            sum = (sum + cnt) % MOD;
        }
        return sum;
    }
};