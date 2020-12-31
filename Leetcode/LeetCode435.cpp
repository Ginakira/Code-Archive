// LeetCode 435 无重叠区间
#include <algorithm>
#include <vector>
using namespace std;

// Solution1: 贪心
// 可以转化为求最大不相交子集，结果用子集总个数减去即可
// 按照右端点升序排列，然后当遇到一个新的区间起点比当前最右端点大时
// 再更新计数，更新最右端点
class Solution {
   public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(),
             [&](auto &a, auto &b) -> bool { return a[1] < b[1]; });
        int count = 1, end = intervals[0][1];
        for (auto &interval : intervals) {
            if (interval[0] >= end) {
                ++count;
                end = interval[1];
            }
        }
        return intervals.size() - count;
    }
};