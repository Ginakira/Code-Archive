// LeetCode 2861 最大合金数

#include <algorithm>
#include <array>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    int maxNumberOfAlloys(int n, int k, int budget,
                          vector<vector<int>>& composition, vector<int>& stock,
                          vector<int>& cost) {
        int ans = 0;
        int max_stock = *max_element(stock.begin(), stock.end());
        for (int i = 0; i < k; ++i) {
            auto& comp = composition[i];
            int left = 0, right = budget + max_stock;
            while (left < right) {
                int mid = (left + right + 1) / 2;
                long long total_cost = 0;
                for (int j = 0; j < n; ++j) {
                    total_cost +=
                        max(1LL * comp[j] * mid - stock[j], 0LL) * cost[j];
                    if (total_cost > budget) {
                        break;
                    }
                }
                if (total_cost <= budget) {
                    left = mid;
                } else {
                    right = mid - 1;
                }
            }
            ans = max(ans, left);
        }
        return ans;
    }
};