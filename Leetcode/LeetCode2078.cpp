// LeetCode 2078 两栋颜色不同且距离最远的房子

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
  int maxDistance(vector<int>& colors) {
    int n = colors.size();
    int c = colors[0];
    if (c != colors.back()) {
      return n - 1;
    }
    int r = n - 2;
    while (colors[r] == c) {
      --r;
    }
    int l = 1;
    while (colors[l] == c) {
      ++l;
    }
    return max(r, n - l - 1);
  }
};