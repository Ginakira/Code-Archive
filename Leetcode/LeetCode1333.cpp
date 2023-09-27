// LLeetCode 1333 餐厅过滤器

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
    vector<int> filterRestaurants(vector<vector<int>> &restaurants,
                                  int veganFriendly, int maxPrice,
                                  int maxDistance) {
        vector<int> ans;
        auto end =
            partition(restaurants.begin(), restaurants.end(), [&](auto &v) {
                return (!veganFriendly || v[2]) && v[3] <= maxPrice &&
                       v[4] <= maxDistance;
            });
        sort(restaurants.begin(), end, [](auto &a, auto &b) {
            return pair{a[1], a[0]} > pair{b[1], b[0]};
        });
        transform(restaurants.begin(), end, back_inserter(ans),
                  [](auto &v) { return v[0]; });
        return ans;
    }
};