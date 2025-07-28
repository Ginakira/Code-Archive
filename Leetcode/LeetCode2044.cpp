// LeetCode 2044 统计按位或能得到最大值的子集数目

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 状态压缩
class Solution {
 public:
  int countMaxOrSubsets(vector<int>& nums) {
    int n = nums.size(), max_ans = 0, cnt = 0, state = 1 << n;
    for (int i = 0; i < state; ++i) {
      int result = 0;
      for (int j = 0; j < n; ++j) {
        if ((i >> j) & 1) {
          result |= nums[j];
        }
      }
      if (result == max_ans) {
        ++cnt;
      } else if (result > max_ans) {
        max_ans = result;
        cnt = 1;
      }
    }
    return cnt;
  }
};

class Solution2 {
 public:
  int countMaxOrSubsets(vector<int>& nums) {
    int total_or = std::reduce(nums.begin(), nums.end(), 0, std::bit_or());
    int ans = 0;
    int n = nums.size();

    auto dfs = [&](this auto&& dfs, int i, int subset_or) -> void {
      if (subset_or == total_or) {
        ans += 1 << (n - i);
        return;
      }
      if (i == n) {
        return;
      }
      dfs(i + 1, subset_or);
      dfs(i + 1, subset_or | nums[i]);
    };

    dfs(0, 0);
    return ans;
  }
};