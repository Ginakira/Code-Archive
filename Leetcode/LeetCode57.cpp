// LeetCode 57 插入区间

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
    vector<vector<int>> insert(vector<vector<int>> &intervals,
                               vector<int> &newInterval) {
        int start = newInterval[0], end = newInterval[1];
        bool inserted = false;
        vector<vector<int>> ans;
        for (const auto &interval : intervals) {
            int cur_start = interval[0], cur_end = interval[1];
            if (cur_start > end) {
                if (!inserted) {
                    ans.push_back({start, end});
                    inserted = true;
                }
                ans.push_back(interval);
            } else if (cur_end < start) {
                ans.push_back(interval);
            } else {
                start = min(start, cur_start);
                end = max(end, cur_end);
            }
        }
        if (!inserted) {
            ans.push_back({start, end});
        }
        return ans;
    }
};
