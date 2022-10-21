// LeetCOde 901 股票价格跨度

#include <algorithm>
#include <limits>
#include <numeric>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class StockSpanner {
   private:
    std::stack<std::pair<int, int>> stk;
    int ind;

   public:
    StockSpanner() {
        stk.emplace(-1, std::numeric_limits<int>::max());
        ind = -1;
    }

    int next(int price) {
        ++ind;
        while (!stk.empty() && stk.top().second <= price) {
            stk.pop();
        }
        int ans = ind - stk.top().first;
        stk.emplace(ind, price);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */