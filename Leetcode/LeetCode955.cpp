// LeetCode 955 删列造序 II

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
    int n = strs.size(), m = strs[0].size();
    vector<string> prefix(n);
    int ans = 0;
    for (int j = 0; j < m; ++j) {
      bool del = false;
      for (int i = 1; i < n; ++i) {
        if (prefix[i] + strs[i][j] < prefix[i - 1] + strs[i - 1][j]) {
          ++ans;
          del = true;
          break;
        }
      }
      if (!del) {
        for (int i = 0; i < n; ++i) {
          prefix[i] += strs[i][j];
        }
      }
    }
    return ans;
  }
};