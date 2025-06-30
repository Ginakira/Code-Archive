// LeetCode 3330 找到初始输入字符串 I

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
  int possibleStringCount(string word) {
    int ans = 1;
    for (int i = 1; i < word.size(); ++i) {
      if (word[i] == word[i - 1]) {
        ++ans;
      }
    }
    return ans;
  }
};