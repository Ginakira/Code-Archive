// LeetCode 1109 航班预订统计

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 差分数组 + 前缀和还原
class Solution {
   public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n, 0);
        for (auto& booking : bookings) {
            int start = booking[0] - 1, end = booking[1] - 1,
                seats = booking[2];
            diff[start] += seats;
            if (end + 1 < n) {
                diff[end + 1] -= seats;
            }
        }
        vector<int> answer;
        partial_sum(diff.begin(), diff.end(), back_inserter(answer));
        return answer;
    }
};