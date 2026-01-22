// LeetCode 3507 移除最小数对使数组有序 I

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
  int minimumPairRemoval(vector<int>& nums) {
    int ans = 0;
    while (nums.size() > 1) {
      bool is_asc = true;
      int min_sum = std::numeric_limits<int>::max();
      int target_idx = -1;
      for (size_t i = 0; i < nums.size() - 1; ++i) {
        int sum = nums[i] + nums[i + 1];
        if (nums[i] > nums[i + 1]) {
          is_asc = false;
        }
        if (sum < min_sum) {
          min_sum = sum;
          target_idx = static_cast<int>(i);
        }
      }
      if (is_asc) {
        break;
      }
      ++ans;
      nums[target_idx] = min_sum;
      nums.erase(nums.begin() + target_idx + 1);
    }
    return ans;
  }
};