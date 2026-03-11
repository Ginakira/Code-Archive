// LeetCode 1009 十进制整数的反码

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int bitwiseComplement(int n) {
    int base = 1;
    while (base < n) {
      base <<= 1;
      base += 1;
    }
    return base ^ n;
  }
};

class Solution2 {
 public:
  int bitwiseComplement(int n) {
    if (n == 0) {
      return 1;
    }
    int cnt = std::countl_zero((uint32_t)n);
    return (~n) & (~0u >> cnt);
  }
};