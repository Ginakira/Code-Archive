// LeetCode 2187 完成旅途的最少时间

#include <algorithm>
#include <array>
#include <numeric>
#include <queue>
#include <ranges>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        ranges::sort(time);
        long long left = 1;
        long long right = 1L * time[0] * totalTrips;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            int cnt = 0;
            for (int t : time) {
                cnt += mid / t;
                if (cnt >= totalTrips) {
                    break;
                }
            }
            if (cnt >= totalTrips) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }
};