// LeetCode 3689 最大子数组总值 I

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
  long long maxTotalValue(vector<int>& nums, int k) {
    return 1LL * k * (*ranges::max_element(nums) - *ranges::min_element(nums));
  }
};