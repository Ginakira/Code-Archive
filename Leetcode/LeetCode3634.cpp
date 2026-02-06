// LeetCode 3634 使数组平衡的最少移除数目

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
  int minRemoval(vector<int>& nums, int k) {
    ranges::sort(nums);
    int max_w = 0, l = 0;
    for (int i = 0; i < nums.size(); ++i) {
      while (1LL * nums[l] * k < nums[i]) {
        ++l;
      }
      max_w = max(max_w, i - l + 1);
    }
    return nums.size() - max_w;
  }
};