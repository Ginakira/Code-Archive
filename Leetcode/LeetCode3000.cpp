// LeetCode 3000 对角线最长的矩形的面积

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
  int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
    int ans = 0, max_len = 0;
    for (const auto& d : dimensions) {
      int w = d[0], h = d[1];
      int len = w * w + h * h;
      if (len > max_len) {
        max_len = len;
        ans = w * h;
      }
      if (len == max_len) {
        ans = max(ans, w * h);
      }
    }
    return ans;
  }
};