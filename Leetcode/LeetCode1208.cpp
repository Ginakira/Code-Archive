// LeetCode 1208 尽可能使字符串相等
#include <string>
using namespace std;

// 滑动窗口
class Solution {
   public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int sum = 0, left = 0, right = 0;

        while (right < n) {
            sum += abs(t[right] - s[right]);
            if (sum > maxCost) {
                sum -= abs(t[left] - s[left]);
                ++left;
            }
            ++right;
        }
        return right - left;
    }
};