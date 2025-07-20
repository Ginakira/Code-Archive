// LeetCode 1957 删除字符使字符串变好

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
  string makeFancyString(string s) {
    string ans;
    for (size_t i = 0; i < s.size(); ++i) {
      if (i >= 2 && s[i] == s[i - 1] && s[i - 1] == s[i - 2]) {
        continue;
      }
      ans.push_back(s[i]);
    }
    return ans;
  }
};