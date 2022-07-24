// LeetCode 1184 公交站间的距离

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int distanceBetweenBusStops(vector<int>& distance, int start,
                                int destination) {
        int total = accumulate(distance.begin(), distance.end(), 0);
        int start_p = min(start, destination), dest_p = max(start, destination);
        int clockwise_sum = accumulate(distance.begin() + start_p,
                                       distance.begin() + dest_p, 0);
        return min(clockwise_sum, total - clockwise_sum);
    }
};