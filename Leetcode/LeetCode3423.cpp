// LeetCode 3423 循环数组中相邻元素的最大差值

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
  int maxAdjacentDistance(vector<int> &nums) {
    int ans = 0;
    nums.emplace_back(nums[0]);
    for (int i = 1; i < nums.size(); ++i) {
      ans = max(ans, abs(nums[i] - nums[i - 1]));
    }
    return ans;
  }
};