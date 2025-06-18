// LeetCode 2966 划分数组并满足最大差限制

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
  vector<vector<int>> divideArray(vector<int>& nums, int k) {
    vector<vector<int>> ans;
    ranges::sort(nums);
    for (int i = 0; i < nums.size(); i += 3) {
      if (nums[i + 2] - nums[i] > k) {
        return {};
      }
      ans.emplace_back(nums.begin() + i, nums.begin() + i + 3);
    }
    return ans;
  }
};