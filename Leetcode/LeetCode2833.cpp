// LeetCode 2833 距离原点最远的点

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
  int furthestDistanceFromOrigin(string moves) {
    auto cal = [](const string& ms) {
      int i = 0;
      for (char c : ms) {
        if (c == 'L') {
          --i;
        } else {
          ++i;
        }
      }
      return abs(i);
    };
    string moves2 = moves;
    ranges::replace(moves, '_', 'L');
    ranges::replace(moves2, '_', 'R');
    return max(cal(moves), cal(moves2));
  }
};