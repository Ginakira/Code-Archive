// LeetCode 2124 检查是否所有 A 都在 B 之前

class Solution {
 public:
  bool checkString(string s) {
    int last_a = -1, first_b = s.size();
    for (int i = 0; i < s.size(); ++i) {
      char c = s[i];
      if (char c = s[i]; c == 'a') {
        last_a = i;
      } else if (first_b == s.size()) {
        first_b = i;
      }
    }
    return last_a < first_b;
  }
};