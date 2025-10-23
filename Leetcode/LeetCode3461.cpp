// LeetCode 3461 判断操作后字符串中的数字是否相等 I

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
  bool hasSameDigits(string s) {
    int n = s.size();
    for (int i = 1; i < n - 1; ++i) {
      for (int j = 0; j < n - i; ++j) {
        s[j] = (s[j] + s[j + 1] - 2 * '0') % 10 + '0';
      }
    }
    return s[0] == s[1];
  }
};