// LeetCode 1848 到目标元素的最小距离

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
  int getMinDistance(vector<int>& nums, int target, int start) {
    int ans = nums.size();
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != target) {
        continue;
      }
      ans = min(ans, abs(i - start));
    }
    return ans;
  }
};