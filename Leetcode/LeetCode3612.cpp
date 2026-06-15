// LeetCode 3612 用特殊操作处理字符串 I

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
  string processStr(string s) {
    string result;
    for (char ch : s) {
      switch (ch) {
        case '*': {
          if (!result.empty()) {
            result.pop_back();
          }
        } break;
        case '#': {
          result += result;
        } break;
        case '%': {
          std::reverse(result.begin(), result.end());
        } break;
        default: {
          result.push_back(ch);
        } break;
      }
    }
    return result;
  }
};