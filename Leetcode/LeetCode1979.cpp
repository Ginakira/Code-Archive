// LeetCode 1979 找出数组的最大公约数

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
  int findGCD(vector<int>& nums) {
    return gcd(*ranges::min_element(nums), *ranges::max_element(nums));
  }
};