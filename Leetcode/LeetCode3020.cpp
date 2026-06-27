// LeetCode 3020 子集中元素的最大数量

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
  int maximumLength(vector<int>& nums) {
    unordered_map<long long, int> cnt;
    for (int num : nums) {
      ++cnt[num];
    }

    int ans = (cnt[1] - 1) | 1;
    cnt.erase(1);

    for (auto& [num, _] : cnt) {
      int res = 0;
      auto x = num;
      while (cnt.contains(x) && cnt[x] >= 2) {
        res += 2;
        x *= x;
      }
      ans = max(ans, res + (cnt.contains(x) ? 1 : -1));
    }
    return ans;
  }
};