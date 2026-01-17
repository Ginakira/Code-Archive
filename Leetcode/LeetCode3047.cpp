// LeetCode 3047 求交集区域内的最大正方形面积

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
  long long largestSquareArea(vector<vector<int>>& bottomLeft,
                              vector<vector<int>>& topRight) {
    int max_side = 0;
    int n = bottomLeft.size();
    for (int i = 0; i < n; ++i) {
      auto &b1 = bottomLeft[i], t1 = topRight[i];
      if (t1[0] - b1[0] <= max_side || t1[1] - b1[1] <= max_side) {
        continue;
      }
      for (int j = 0; j < i; ++j) {
        auto &b2 = bottomLeft[j], t2 = topRight[j];
        int w = min(t1[0], t2[0]) - max(b1[0], b2[0]);
        int h = min(t1[1], t2[1]) - max(b1[1], b2[1]);
        max_side = max(max_side, min(w, h));
      }
    }
    return 1LL * max_side * max_side;
  }
};