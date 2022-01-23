// LeetCode 2034 股票价格波动

#include <algorithm>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class StockPrice {
   private:
    unordered_map<int, int> prices;
    multiset<int> prices_set;
    int last_time = 0;

   public:
    StockPrice() {}

    void update(int timestamp, int price) {
        if (prices.count(timestamp)) {
            int old_price = prices[timestamp];
            prices_set.erase(prices_set.find(old_price));
        }
        prices[timestamp] = price;
        prices_set.insert(price);
        last_time = max(last_time, timestamp);
    }

    int current() { return prices[last_time]; }

    int maximum() { return *prices_set.rbegin(); }

    int minimum() { return *prices_set.begin(); }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */