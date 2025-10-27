// LeetCode 3354 使数组元素等于零

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
  int countValidSelections(vector<int>& nums) {
    int ans = 0;
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    auto go = [&](int start, int dir) {
      int cur = start;
      int cur_sum = 0;
      vector<int> temp = nums;
      while (cur >= 0 && cur < n) {
        if (temp[cur] > 0) {
          --temp[cur];
          dir *= -1;
          ++cur_sum;
        }
        cur += dir;
      }
      if (cur_sum == sum) {
        ++ans;
      }
    };
    for (int i = 0; i < n; ++i) {
      if (nums[i] == 0) {
        go(i, 1);
        go(i, -1);
      }
    }
    return ans;
  }
};

class Solution2 {
 public:
  int countValidSelections(vector<int>& nums) {
    int ans = 0, pre_sum = 0;
    int sum = accumulate(nums.begin(), nums.end(), 0);
    for (int num : nums) {
      if (num) {
        pre_sum += num;
      } else if (pre_sum * 2 == sum) {
        ans += 2;
      } else if (abs(pre_sum * 2 - sum) == 1) {
        ans += 1;
      }
    }
    return ans;
  }
};