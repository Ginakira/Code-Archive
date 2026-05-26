// LeetCode 3120 统计特殊字母的数量 I
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
  int numberOfSpecialChars(string word) {
    std::unordered_set<char> s(word.begin(), word.end());
    int ans = 0;
    for (char c = 'a'; c <= 'z'; ++c) {
      if (s.count(c) && s.count(toupper(c))) {
        ++ans;
      }
    }
    return ans;
  }
};