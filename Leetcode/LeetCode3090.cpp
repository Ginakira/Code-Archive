// LeetCode 3090 每个字符最多出现两次的最长子字符串

class Solution {
 public:
  int maximumLengthSubstring(string s) {
    std::array<int, 26> cnt{0};
    int max_len = 0;
    for (int l = 0, r = 0; r < s.size(); ++r) {
      char ch = s[r];
      ++cnt[ch - 'a'];
      while (cnt[ch - 'a'] > 2 && l < r) {
        --cnt[s[l] - 'a'];
        ++l;
      }
      max_len = max(max_len, r - l + 1);
    }
    return max_len;
  }
};