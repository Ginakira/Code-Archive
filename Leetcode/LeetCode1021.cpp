// LeetCode 1021 删除最外层的括号

class Solution {
 public:
  string removeOuterParentheses(string s) {
    string result, cur;
    for (int lcnt = 0, rcnt = 0; char c : s) {
      cur.push_back(c);
      if (c == '(') {
        ++lcnt;
      } else {
        ++rcnt;
      }
      if (lcnt == rcnt) {
        cur = cur.substr(1, cur.size() - 2);
        result += cur;
        cur = {};
      }
    }
    return result;
  }
};