// LeetCode 2154 将找到的值乘以 2

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
  int findFinalValue(vector<int>& nums, int original) {
    constexpr int kMaxNum = 1000;
    std::array<bool, kMaxNum + 1> mark{false};
    for (int num : nums) {
      mark[num] = true;
    }
    while (original <= kMaxNum && mark[original]) {
      original *= 2;
    }
    return original;
  }
};