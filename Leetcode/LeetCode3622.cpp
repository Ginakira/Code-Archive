// LeetCode 3622 判断整除性

class Solution {
 public:
  bool checkDivisibility(int n) {
    int sum = 0, prod = 1, num = n;
    while (num) {
      int digit = num % 10;
      sum += digit;
      prod *= digit;
      num /= 10;
    }
    return n % (sum + prod) == 0;
  }
};