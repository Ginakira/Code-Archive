// LeetCode 1523 在区间范围内统计奇数个数

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
  int countOdds(int low, int high) {
    return (high - low) / 2 + (low & 1 || high & 1);
  }
};