// LeetCode 2839 判断通过操作能否让字符串相等 I

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
  bool canBeEqual(string s1, string s2) {
    if (s1 == s2) {
      return true;
    }
    swap(s1[1], s1[3]);
    if (s1 == s2) {
      return true;
    }
    std::string s = s1;
    swap(s[0], s[2]);
    if (s == s2) {
      return true;
    }
    swap(s[1], s[3]);
    if (s == s2) {
      return true;
    }
    return false;
  }
};