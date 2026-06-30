// LeetCode 1358 包含所有三种字符的子字符串数目

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
  int numberOfSubstrings(string s) {
    std::array<int, 3> cnt{};
    int ans = 0, left = 0;
    for (char c : s) {
      ++cnt[c - 'a'];
      while (cnt[0] && cnt[1] && cnt[2]) {
        --cnt[s[left] - 'a'];
        ++left;
      }
      ans += left;
    }
    return ans;
  }
};