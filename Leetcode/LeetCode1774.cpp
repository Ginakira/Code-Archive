// LeetCode 1774 最接近目标价格的甜点成本

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   private:
    void dfs(const vector<int> &baseCosts, const vector<int> &toppingCosts,
             int top_ind, int cur_cost, int &ans, int target) {
        if (abs(ans - target) < cur_cost - target) {
            return;
        }
        if (abs(ans - target) >= abs(cur_cost - target)) {
            if (abs(ans - target) > abs(cur_cost - target)) {
                ans = cur_cost;
            } else {
                ans = min(ans, cur_cost);
            }
        }
        if (top_ind == toppingCosts.size()) {
            return;
        }
        dfs(baseCosts, toppingCosts, top_ind + 1, cur_cost, ans, target);
        dfs(baseCosts, toppingCosts, top_ind + 1,
            cur_cost + toppingCosts[top_ind], ans, target);
        dfs(baseCosts, toppingCosts, top_ind + 1,
            cur_cost + toppingCosts[top_ind] * 2, ans, target);
    }

   public:
    int closestCost(vector<int> &baseCosts, vector<int> &toppingCosts,
                    int target) {
        int ans = *min_element(baseCosts.begin(), baseCosts.end());
        for (int base : baseCosts) {
            dfs(baseCosts, toppingCosts, 0, base, ans, target);
        }
        return ans;
    }
};