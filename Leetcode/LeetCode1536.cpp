// LeetCode 1536 排布二进制网格的最少交换次数

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
  int minSwaps(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<int> cnts(n, 0);
    for (int i = 0; i < n; ++i) {
      for (int j = m - 1; j >= 0 && grid[i][j] == 0; --j) {
        ++cnts[i];
      }
    }
    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
      int j = i;
      while (j < n && cnts[j] < n - 1 - i) {
        ++j;
      }
      if (j == n) {
        return -1;
      }
      ans += j - i;
      copy_backward(cnts.begin() + i, cnts.begin() + j, cnts.begin() + j + 1);
    }
    return ans;
  }
};