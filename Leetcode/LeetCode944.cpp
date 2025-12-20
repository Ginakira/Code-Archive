// LeetCode 944 删列造序

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
  int minDeletionSize(vector<string>& strs) {
    int ans = 0;
    int n = strs.size(), m = strs[0].size();
    for (int j = 0; j < m; ++j) {
      for (int i = 1; i < n; ++i) {
        if (strs[i][j] < strs[i - 1][j]) {
          ++ans;
          break;
        }
      }
    }
    return ans;
  }
};