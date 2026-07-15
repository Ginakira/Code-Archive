// LeetCode 3658 奇数和偶数和的最大公约数

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
  int gcdOfOddEvenSums(int n) {
    int sum_odd = (1 + (1 + 2 * (n - 1))) * n / 2;
    int sum_even = (2 + (2 + 2 * (n - 1))) * n / 2;
    return gcd(sum_odd, sum_even);
  }
};