// LeetCode 1446 连续字符

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// DP
class Solution {
   public:
    int maxPower(string s) {
        int n = s.size();
        vector<int> dp(n, 1);
        int max_power = 1;
        for (int i = 1; i < n; ++i) {
            if (s[i] == s[i - 1]) {
                dp[i] = dp[i - 1] + 1;
            }
            max_power = max(max_power, dp[i]);
        }
        return max_power;
    }
};

// 滑动窗口
class Solution2 {
   public:
    int maxPower(string s) {
        int n = s.size();
        int left = 0, right = 0;
        int max_power = 1;

        while (right < n) {
            if (s[right] != s[left]) {
                left = right;
            }
            max_power = max(max_power, right - left + 1);
            ++right;
        }
        return max_power;
    }
};