// LeetCode 495 提莫攻击
#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans = 0, current = 0;
        for (const int& time : timeSeries) {
            current = max(current, time);
            ans += time + duration - current;
            current = time + duration;
        }
        return ans;
    }
};