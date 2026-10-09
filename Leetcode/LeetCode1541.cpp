// LeetCode 1541 平衡括号字符串的最少插入次数

class Solution {
 public:
  int minInsertions(string s) {
    int n = s.size();
    int left = 0;
    int ans = 0;

    for (int i = 0; i < n; ++i) {
      if (s[i] == '(') {
        ++left;
        continue;
      }

      if (left > 0) {
        --left;
      } else {
        ++ans;
      }

      if (i < n - 1 && s[i + 1] == ')') {
        ++i;
      } else {
        ++ans;
      }
    }

    return ans + left * 2;
  }
};