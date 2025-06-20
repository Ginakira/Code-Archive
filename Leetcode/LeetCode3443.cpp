// LeetCode 3443 K次修改后的最大曼哈顿距离

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
  int maxDistance(string s, int k) {
    int ans = 0;
    int cnt['X']{0};
    for (char ch : s) {
      ++cnt[ch];
      int left = k;
      auto f = [&](int a, int b) {
        int d = min({a, b, left});
        left -= d;
        return abs(a - b) + 2 * d;
      };
      ans = max(ans, f(cnt['N'], cnt['S']) + f(cnt['W'], cnt['E']));
    }
    return ans;
  }
};