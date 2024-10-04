// LeetCode 1870 准时到达的列车最小时速

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
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        long long hour_norm = llround(100L * hour);
        if (hour_norm <= (n - 1) * 100) {
            return -1;
        }
        int l = 1, r = 1e7;
        while (l < r) {
            int mid = l + (r - l) / 2;
            long long t = 0;
            for (int i = 0; i < n - 1; ++i) {
                t += (dist[i] - 1) / mid + 1;
            }
            // t + dist[n - 1] / mid <= hour
            // mid * t + dist[n - 1] <= hour * mid
            // 100(mid * t + dist[n - 1]) <= mid * hour_norm
            t *= mid;
            t += dist[n - 1];
            if (t * 100 <= hour_norm * mid) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};