// LeetCode 2785 将字符串中的元音字母排序

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
  string sortVowels(string s) {
    int n = s.size();
    vector<int> pos;
    vector<char> vowels;
    auto is_vowel = [](char ch) {
      ch = tolower(ch);
      return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    };
    for (int i = 0; i < n; ++i) {
      if (is_vowel(s[i])) {
        pos.emplace_back(i);
        vowels.emplace_back(s[i]);
      }
    }
    ranges::sort(vowels);
    for (int i = 0; i < vowels.size(); ++i) {
      s[pos[i]] = vowels[i];
    }
    return s;
  }
};