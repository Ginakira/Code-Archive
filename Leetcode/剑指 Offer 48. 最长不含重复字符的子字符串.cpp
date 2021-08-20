// 剑指 Offer 48. 最长不含重复字符的子字符串

#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int n = s.size(), left = 0, right = 0, ans = 0;
        while (right < n) {
            if (st.count(s[right])) {
                st.erase(s[left]);
                ++left;
            } else {
                st.insert(s[right]);
                ++right;
                ans = max(ans, right - left);
            }
        }
        return ans;
    }
};