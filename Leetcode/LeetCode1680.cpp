// LeetCode 1680 连接连续二进制数字

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
  int concatenatedBinary(int n) {
    constexpr int MOD = 1e9 + 7;
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
      int w = bit_width((uint32_t)i);
      ans = (ans << w | i) % MOD;
    }
    return ans;
  }
};