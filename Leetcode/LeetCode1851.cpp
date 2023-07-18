// LeetCode 1851 包含每个查询的最小区间

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
    vector<int> minInterval(vector<vector<int>> &intervals,
                            vector<int> &queries) {
        vector<int> ans(queries.size(), -1);
        vector<int> q_ind(queries.size());
        std::iota(q_ind.begin(), q_ind.end(), 0);

        std::sort(q_ind.begin(), q_ind.end(),
                  [&queries](int a, int b) { return queries[a] < queries[b]; });
        std::sort(intervals.begin(), intervals.end(),
                  [](auto &a, auto &b) { return a[0] < b[0]; });
        priority_queue<std::tuple<int, int, int>> pq;

        int cur = 0;
        for (auto qi : q_ind) {
            while (cur < intervals.size() && intervals[cur][0] <= queries[qi]) {
                int len = intervals[cur][1] - intervals[cur][0] + 1;
                pq.emplace(-len, intervals[cur][0], intervals[cur][1]);
                ++cur;
            }
            while (!pq.empty() && std::get<2>(pq.top()) < queries[qi]) {
                pq.pop();
            }
            if (!pq.empty()) {
                ans[qi] = -std::get<0>(pq.top());
            }
        }
        return ans;
    }
};
