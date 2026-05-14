// LeetCode 2784 检查数组是否是好的

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
  bool isGood(vector<int>& nums) {
    ranges::sort(nums);
    for (int i = 0; i < nums.size() - 1; ++i) {
      if (nums[i] != i + 1) {
        return false;
      }
    }
    return nums.back() == nums.size() - 1;
  }
};