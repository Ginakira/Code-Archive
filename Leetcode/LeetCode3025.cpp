// LeetCode 3025 人员站位的方案数I

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
  int numberOfPairs(vector<vector<int>>& points) {
    int ans = 0;
    int n = points.size();
    for (int i = 0; i < n; ++i) {
      auto& pa = points[i];
      for (int j = 0; j < n; ++j) {
        auto& pb = points[j];
        if (i == j || !(pa[0] <= pb[0] && pa[1] >= pb[1])) {
          continue;
        }
        if (n == 2) {
          ++ans;
          continue;
        }
        bool valid = false;
        for (int k = 0; k < n; ++k) {
          if (k == i || k == j) {
            continue;
          }

          auto& pc = points[k];
          bool is_x_contained = pc[0] >= pa[0] && pc[0] <= pb[0];
          bool is_y_contained = pc[1] <= pa[1] && pc[1] >= pb[1];
          if (is_x_contained && is_y_contained) {
            valid = true;
            break;
          }
        }
        if (!valid) {
          ++ans;
        }
      }
    }
    return ans;
  }
};