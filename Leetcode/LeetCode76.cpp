// LeetCode 76 最小覆盖子串

#include <algorithm>
#include <climits>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 滑动窗口
class Solution {
   public:
    string minWindow(string s, string t) {
        vector<int> cnt(128);
        int n = s.size(), left = 0, right = 0;
        int need = t.size();  // 还剩多少个字符可以覆盖t
        int min_left = 0, min_len = INT_MAX;

        for (char &c : t) {
            ++cnt[c];
        }

        while (right < n) {
            if (cnt[s[right]] > 0) --need;
            --cnt[s[right]];
            ++right;             // 扩展右边界
            while (need == 0) {  // 窗口中已经覆盖了t，收缩左边界
                if (right - left < min_len) {
                    min_left = left;
                    min_len = right - left;
                }
                if (++cnt[s[left]] > 0) ++need;
                ++left;
            }
        }

        return min_len == INT_MAX ? string() : s.substr(min_left, min_len);
    }
};