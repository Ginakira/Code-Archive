// LeetCode 2273 移除字母异位词后的结果数组

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
  vector<string> removeAnagrams(vector<string>& words) {
    vector<string> ans;
    ans.reserve(words.size());
    std::string pre;
    for (const auto& word : words) {
      string s = word;
      ranges::sort(s);
      if (ans.empty() || s != pre) {
        ans.emplace_back(word);
      }
      pre = std::move(s);
    }
    return ans;
  }
};