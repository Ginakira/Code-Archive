// LeetCode 3536 两个数字的最大乘积

#include <algorithm>
#include <array>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxProduct(int n) {
    int max_a = 0, max_b = 0;
    while (n) {
      int digit = n % 10;
      if (digit >= max_a) {
        max_b = max_a;
        max_a = digit;
      } else if (digit > max_b) {
        max_b = digit;
      }
      n /= 10;
    }
    return max_a * max_b;
  }
};