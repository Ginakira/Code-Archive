// LeetCode 3713 最长的平衡子串 I

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
  int longestBalanced(string s) {
    int ans = 0;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
      std::array<int, 26> cnt{0};
      for (int j = i; j < n; ++j) {
        int target = ++cnt[s[j] - 'a'];
        for (int c : cnt) {
          if (c && c != target) {
            target = -1;
            break;
          }
        }
        if (target != -1) {
          ans = max(ans, j - i + 1);
        }
      }
    }
    return ans;
  }
};