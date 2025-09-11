// LeetCode 3227 字符串元音游戏

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
  bool doesAliceWin(string s) {
    return ranges::any_of(s, [](char c) {
      return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    });
  }
};