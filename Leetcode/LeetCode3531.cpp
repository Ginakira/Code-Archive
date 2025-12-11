// LeetCode 3531 统计被覆盖的建筑

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
  int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
    constexpr int kMAX = std::numeric_limits<int>::max();
    std::vector<int> x_min(n + 1, kMAX), y_min(n + 1, kMAX);
    std::vector<int> x_max(n + 1), y_max(n + 1);
    for (const auto& building : buildings) {
      int x = building[0], y = building[1];
      x_min[x] = min(x_min[x], y);
      x_max[x] = max(x_max[x], y);
      y_min[y] = min(y_min[y], x);
      y_max[y] = max(y_max[y], x);
    }
    return ranges::count_if(buildings, [&](const vector<int>& building) {
      int x = building[0], y = building[1];
      return y > x_min[x] && y < x_max[x] && x > y_min[y] && x < y_max[y];
    });
  }
};