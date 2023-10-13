// LeetCode 1488 避免洪水泛滥

#include <algorithm>
#include <array>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> avoidFlood(vector<int> &rains) {
        size_t n = rains.size();
        vector<int> ans(n, 1);
        set<int> free_days;
        unordered_map<int, int> last_rainy;
        for (size_t i = 0; i < n; ++i) {
            if (rains[i] == 0) {
                free_days.emplace(i);
                continue;
            }
            ans[i] = -1;
            int lake = rains[i];
            if (last_rainy.count(lake)) {
                auto it = free_days.lower_bound(last_rainy[lake]);
                if (it == free_days.end()) {
                    return {};
                }
                ans[*it] = lake;
                free_days.erase(it);
            }
            last_rainy[lake] = i;
        }
        return ans;
    }
};
