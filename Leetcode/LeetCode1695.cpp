// LeetCode 1695 删除子数组的最大得分

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
  int maximumUniqueSubarray(vector<int>& nums) {
    std::unordered_set<int> us;
    int cur_sum = 0;
    int left = 0;
    int ans = 0;
    for (int num : nums) {
      while (us.contains(num)) {
        cur_sum -= nums[left];
        us.erase(nums[left]);
        ++left;
      }
      us.emplace(num);
      cur_sum += num;
      ans = max(ans, cur_sum);
    }
    return ans;
  }
};