// LeetCode 1629 按键持续时间最长的键

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int n = releaseTimes.size();
        int max_time = releaseTimes[0], max_key = keysPressed[0];

        for (int i = 1; i < n; ++i) {
            int press_time = releaseTimes[i] - releaseTimes[i - 1];
            if (press_time > max_time ||
                (press_time == max_time && keysPressed[i] > max_key)) {
                max_key = keysPressed[i];
                max_time = press_time;
            }
        }
        return max_key;
    }
};