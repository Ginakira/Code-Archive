// LeetCode 3010 将数组分成最小总代价的子数组 I
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
  int minimumCost(vector<int>& nums) {
    sort(nums.begin() + 1, nums.end());
    return nums[0] + nums[1] + nums[2];
  }
};