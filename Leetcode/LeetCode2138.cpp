// LeetCode 2138 将字符串拆分为若干长度为 K 的组

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
  vector<string> divideString(string s, int k, char fill) {
    int n = s.size();
    vector<string> ans;
    for (int i = 0; i < n; i += k) {
      ans.emplace_back(s.substr(i, k));
    }
    auto& back_s = ans.back();
    if (back_s.size() < k) {
      back_s += string(k - back_s.size(), fill);
    }
    return ans;
  }
};