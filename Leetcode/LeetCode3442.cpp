// LeetCode 3442 奇偶频次间的最大差值I

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
  int maxDifference(string s) {
    int max_odd = 0, min_even = s.size() + 1;
    std::array<int, 26> cnt{{0}};
    for (char c : s) {
      ++cnt[c - 'a'];
    }
    for (int num : cnt) {
      if (num & 1) {
        max_odd = max(max_odd, num);
      } else if (num > 0) {
        min_even = min(min_even, num);
      }
    }
    return max_odd - min_even;
  }
};