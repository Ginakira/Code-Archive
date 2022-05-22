// LeetCode 436 寻找右区间

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        size_t n = intervals.size();
        vector<tuple<int, int>> start_points, end_points;
        for (size_t i = 0; i < n; ++i) {
            start_points.emplace_back(intervals[i][0], i);
            end_points.emplace_back(intervals[i][1], i);
        }
        sort(start_points.begin(), start_points.end());
        sort(end_points.begin(), end_points.end());
        vector<int> ans(n, -1);
        for (size_t i = 0, j = 0; i < n && j < n; ++i) {
            while (j < n && get<0>(end_points[i]) > get<0>(start_points[j])) {
                ++j;
            }
            if (j < n) {
                ans[get<1>(end_points[i])] = get<1>(start_points[j]);
            }
        }
        return ans;
    }
};