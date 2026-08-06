// LeetCode 3345 最小可整除数位积 I

class Solution {
 public:
  int smallestNumber(int n, int t) {
    auto valid = [t](int num) {
      int ans = 1;
      while (num) {
        ans *= num % 10;
        num /= 10;
      }
      return ans % t == 0;
    };
    while (!valid(n)) {
      ++n;
    }
    return n;
  }
};