// LeetCode 2419 按位与最大的最长子数组

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
  int longestSubarray(vector<int>& nums) {
    int max_num = 0, ans = 0, cnt = 0;
    for (int num : nums) {
      if (num > max_num) {
        max_num = num;
        ans = cnt = 1;
      } else if (num == max_num) {
        ++cnt;
        ans = max(ans, cnt);
      } else {
        cnt = 0;
      }
    }
    return ans;
  }
};