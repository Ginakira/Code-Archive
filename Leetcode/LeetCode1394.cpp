// LeetCode 1394 找出数组中的幸运数

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

#include <ranges>

class Solution {
 public:
  int findLucky(vector<int>& arr) {
    map<int, int> cnt;
    for (auto num : arr) {
      ++cnt[num];
    }
    for (auto& [n, c] : cnt | std::views::reverse) {
      if (n == c) {
        return n;
      }
    }
    return -1;
  }
};