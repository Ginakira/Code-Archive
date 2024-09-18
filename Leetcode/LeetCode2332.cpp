// LeetCode 2332 坐上公交的最晚时间

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
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers,
                              int capacity) {
        ranges::sort(buses);
        ranges::sort(passengers);
        int n = passengers.size();
        int pos = 0, space = 0;
        for (int arrive : buses) {
            space = capacity;
            while (space > 0 && pos < n && passengers[pos] <= arrive) {
                --space;
                ++pos;
            }
        }
        --pos;
        int last_catch_time = space > 0 ? buses.back() : passengers[pos];
        while (pos >= 0 && passengers[pos] == last_catch_time) {
            --pos;
            --last_catch_time;
        }
        return last_catch_time;
    }
};