// LeetCode 3498 字符串的反转度

class Solution {
 public:
  int reverseDegree(string s) {
    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
      ans += (i + 1) * (26 - s[i] + 'a');
    }
    return ans;
  }
};