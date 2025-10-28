// LeetCode 3370 仅含置位位的最小整数

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
  int smallestNumber(int n) { return (1 << (32 - __builtin_clz(n))) - 1; }
};