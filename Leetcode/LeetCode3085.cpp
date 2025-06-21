// LeetCode 3085 成为 K 特殊字符串需要删除的最少字符数

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
  int minimumDeletions(string word, int k) {
    std::array<int, 26> cnt{{0}};
    for (auto& ch : word) {
      ++cnt[ch - 'a'];
    }
    int ans = word.size();
    for (int target_cnt : cnt) {
      if (target_cnt == 0) {
        continue;
      }
      int del_cnt = 0;
      for (int c : cnt) {
        if (target_cnt > c) {
          del_cnt += c;
        } else if (c > target_cnt + k) {
          del_cnt += c - (target_cnt + k);
        }
      }
      ans = min(ans, del_cnt);
    }
    return ans;
  }
};