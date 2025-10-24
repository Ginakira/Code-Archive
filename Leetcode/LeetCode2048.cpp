// LeetCode 2048 下一个更大的数值平衡数

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
  int nextBeautifulNumber(int n) {
    static constexpr int kMaxAns = 1224444;
    for (int i = n + 1; i <= kMaxAns; ++i) {
      int cnt[10]{0};
      for (int x = i; x > 0; x /= 10) {
        ++cnt[x % 10];
      }
      bool ok = true;
      for (int x = i; x > 0; x /= 10) {
        if (cnt[x % 10] != x % 10) {
          ok = false;
          break;
        }
      }
      if (ok) {
        return i;
      }
    }
    return -1;
  }
};