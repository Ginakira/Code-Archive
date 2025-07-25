// LeetCode 3487 删除后的最大子数组元素和

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
  int maxSum(vector<int>& nums) {
    unordered_set<int> seen;
    for (int num : nums) {
      if (num > 0) {
        seen.emplace(num);
      }
    }
    if (seen.empty()) {
      return *ranges::max_element(nums);
    }
    return accumulate(seen.begin(), seen.end(), 0);
  }
};