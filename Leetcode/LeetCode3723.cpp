// LeetCode 3723 数位平方和的最大值

class Solution {
 public:
  string maxSumOfSquares(int num, int sum) {
    if (num * 9 < sum) {
      return {};
    }
    string ans(sum / 9, '9');
    if (sum % 9) {
      ans += '0' + sum % 9;
    }
    return ans + string(num - ans.size(), '0');
  }
};