// LeetCode 3516 找到最近的人

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
  int findClosest(int x, int y, int z) {
    auto res = abs(z - x) <=> abs(z - y);
    if (res < 0) {
      return 1;
    } else if (res > 0) {
      return 2;
    }
    return 0;
  }
};