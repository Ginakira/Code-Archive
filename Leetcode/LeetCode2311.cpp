// LeetCode 2311 小于等于 K 的最长二进制子序列

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
  int longestSubsequence(string s, int k) {
    int cur = 0;
    int ans = 0;
    int bits = 32 - __builtin_clz(k);
    for (int i = 0; i < s.size(); ++i) {
      char ch = s[s.size() - i - 1];
      if (ch == '1') {
        if (i < bits && cur + (1 << i) <= k) {
          cur += 1 << i;
          ++ans;
        }
      } else {
        ++ans;
      }
    }
    return ans;
  }
};