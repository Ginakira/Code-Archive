// LeetCode 2904 最短且字典序最小的美丽字符串

class Solution {
 public:
  string shortestBeautifulSubstring(string s, int k) {
    if (ranges::count(s, '1') < k) {
      return "";
    }
    for (int size = k;; ++size) {
      string ans = "";
      for (int i = size; i <= s.size(); ++i) {
        string t = s.substr(i - size, size);
        if ((ans.empty() || t < ans) && ranges::count(t, '1') == k) {
          ans = t;
        }
      }
      if (!ans.empty()) {
        return ans;
      }
    }
  }
};