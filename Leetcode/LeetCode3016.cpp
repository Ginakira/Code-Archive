// LeetCode 3016 输入单词需要的最少按键次数 II

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
  int minimumPushes(string word) {
    std::array<int, 26> cnt{0};
    for (char c : word) {
      ++cnt[c - 'a'];
    }
    ranges::sort(cnt, greater<int>());

    constexpr int kBtnCnt = 8;
    int ans = 0;
    int cur_layer = 1, cur_remain = kBtnCnt;
    for (int c : cnt) {
      if (c == 0) {
        continue;
      }
      if (cur_remain == 0) {
        ++cur_layer;
        cur_remain = kBtnCnt;
      }
      ans += c * cur_layer;
      --cur_remain;
    }
    return ans;
  }
};