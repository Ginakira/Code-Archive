// LeetCode 3121 统计特殊字母的数量 II

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
  int numberOfSpecialChars(string word) {
    int n = word.size();
    array<int, 26> lower_idx_max, upper_idx_min;
    lower_idx_max.fill(-1);
    upper_idx_min.fill(n);
    for (int i = 0; i < n; ++i) {
      char ch = word[i];
      if (islower(ch)) {
        lower_idx_max[ch - 'a'] = max(lower_idx_max[ch - 'a'], i);
      } else {
        upper_idx_min[ch - 'A'] = min(upper_idx_min[ch - 'A'], i);
      }
    }
    int ans = 0;
    for (int i = 0; i < lower_idx_max.size(); ++i) {
      if (lower_idx_max[i] >= 0 && upper_idx_min[i] < n &&
          lower_idx_max[i] < upper_idx_min[i]) {
        ++ans;
      }
    }
    return ans;
  }
};