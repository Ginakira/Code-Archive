// LeetCode 3499 操作后最大活跃区段数

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
  int maxActiveSectionsAfterTrade(string s) {
    int total1 = 0, mx = 0, pre0 = numeric_limits<int>::min(), cnt = 0;
    for (int i = 0; i < s.size(); ++i) {
      ++cnt;
      if (i == s.size() - 1 || s[i] != s[i + 1]) {
        if (s[i] == '1') {
          total1 += cnt;
        } else {
          mx = max(mx, pre0 + cnt);
          pre0 = cnt;
        }
        cnt = 0;
      }
    }
    return total1 + mx;
  }
};