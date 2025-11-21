// LeetCode 1930 长度为 3 的不同回文子序列

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
  int countPalindromicSubsequence(string s) {
    int ans = 0;
    for (char ch = 'a'; ch <= 'z'; ++ch) {
      int i = s.find(ch);
      if (i == string::npos) {
        continue;
      }
      int j = s.rfind(ch);

      std::array<bool, 26> has{false};
      for (int k = i + 1; k < j; ++k) {
        if (!has[s[k] - 'a']) {
          has[s[k] - 'a'] = true;
          ++ans;
        }
      }
    }
    return ans;
  }
};