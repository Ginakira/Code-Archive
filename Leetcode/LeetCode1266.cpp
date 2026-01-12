// LeetCode 1266 访问所有点的最小时间

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
  int minTimeToVisitAllPoints(vector<vector<int>>& points) {
    int x = points[0][0], y = points[0][1];
    int ans = 0;
    for (const auto& p : points) {
      int px = p[0], py = p[1];
      int dx = abs(px - x), dy = abs(py - y);
      ans += min(dx, dy) + abs(dx - dy);
      x = px, y = py;
    }
    return ans;
  }
};