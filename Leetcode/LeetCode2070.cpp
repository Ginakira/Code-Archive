// LeetCode 2070 每一个查询的最大美丽值

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
    vector<int> maximumBeauty(vector<vector<int>>& items,
                              vector<int>& queries) {
        int n = items.size(), m = queries.size();
        vector<int> ans;
        ans.reserve(m);
        ranges::sort(items,
                     [](const auto& a, const auto& b) { return a[0] < b[0]; });
        for (int i = 1; i < n; ++i) {
            items[i][1] = max(items[i][1], items[i - 1][1]);
        }

        auto query = [&](int q) -> int {
            auto it = ranges::upper_bound(
                items, vector<int>{q},
                [](const auto& a, const auto& b) { return a[0] < b[0]; });
            if (it == items.begin()) {
                return 0;
            }
            return (*(--it))[1];
        };

        for (auto& q : queries) {
            ans.push_back(query(q));
        }
        return ans;
    }
};