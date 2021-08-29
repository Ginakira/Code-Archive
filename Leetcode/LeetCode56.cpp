// LeetCode 56 合并区间

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        result.emplace_back(intervals[0]);
        for (int i = 1; i < n; ++i) {
            const vector<int>& interval = intervals[i];
            if (interval[0] <= result.back()[1]) {
                result.back()[1] = max(interval[1], result.back()[1]);
            } else {
                result.emplace_back(interval);
            }
        }
        return result;
    }
};