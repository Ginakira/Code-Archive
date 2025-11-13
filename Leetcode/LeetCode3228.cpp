// LeetCode 3228 将 1 移动到末尾的最大操作次数

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
  int maxOperations(string s) {
    int ans = 0, cnt1 = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '1') {
        ++cnt1;
      } else if (i > 0 && s[i - 1] == '1') {
        ans += cnt1;
      }
    }
    return ans;
  }
};