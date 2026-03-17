// LeetCode 1727 重新排列后的最大子矩阵

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
  int largestSubmatrix(vector<vector<int>>& matrix) {
    int n = matrix[0].size();
    vector<int> heights(n);
    int ans = 0;

    for (const auto& row : matrix) {
      for (int j = 0; j < n; ++j) {
        int x = row[j];
        if (x == 0) {
          heights[j] = 0;
        } else {
          ++heights[j];
        }
      }

      auto hs = heights;
      ranges::sort(hs);
      for (int i = 0; i < n; ++i) {
        ans = max(ans, (n - i) * hs[i]);
      }
    }

    return ans;
  }
};