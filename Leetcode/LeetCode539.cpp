// LeetCode 539 最小时间差

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int findMinDifference(vector<string>& timePoints) {
        const int DAY_TOTAL_MINUTES = 1440;
        if (timePoints.size() > DAY_TOTAL_MINUTES) {
            return 0;
        }
        sort(timePoints.begin(), timePoints.end());

        auto get_minutes = [](const string& s) {
            return ((s[0] - '0') * 10 + (s[1] - '0')) * 60 + (s[3] - '0') * 10 +
                   (s[4] - '0');
        };

        auto n = timePoints.size();
        int min_diff = INT_MAX;
        int t0_minutes = get_minutes(timePoints[0]);
        int pre_minutes = t0_minutes;
        for (size_t i = 1; i < n; ++i) {
            int minutes = get_minutes(timePoints[i]);
            min_diff = min(min_diff, minutes - pre_minutes);
            if (min_diff == 0) {
                break;
            }
            pre_minutes = minutes;
        }
        min_diff = min(min_diff, t0_minutes + DAY_TOTAL_MINUTES - pre_minutes);
        return min_diff;
    }
};