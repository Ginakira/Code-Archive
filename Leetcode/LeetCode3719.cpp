// LeetCode 3719 最长平衡子数组 I

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
  int longestBalanced(vector<int>& nums) {
    int ans = 0;
    for (int i = 0; i < nums.size(); ++i) {
      unordered_map<int, int> odd, even;
      for (int j = i; j < nums.size(); ++j) {
        auto& mp = (nums[j] & 1) ? odd : even;
        ++mp[nums[j]];

        if (odd.size() == even.size()) {
          ans = max(ans, j - i + 1);
        }
      }
    }
    return ans;
  }
};