// LeetCode 1935 可以输入的最大单词数

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
  int canBeTypedWords(string text, string brokenLetters) {
    std::array<bool, 26> broken{false};
    for (char ch : brokenLetters) {
      broken[ch - 'a'] = true;
    }
    int ans = 0;
    text.push_back(' ');
    for (bool valid = true; char ch : text) {
      if (ch == ' ') {
        if (valid) {
          ++ans;
        }
        valid = true;
        continue;
      } else if (!valid) {
        continue;
      }
      if (broken[ch - 'a']) {
        valid = false;
      }
    }
    return ans;
  }
};

class Solution2 {
 public:
  int canBeTypedWords(string text, string brokenLetters) {
    std::array<bool, 26> broken{false};
    for (char ch : brokenLetters) {
      broken[ch - 'a'] = true;
    }
    stringstream ss(text);
    string word;
    int cnt = 0;
    while (ss >> word) {
      if (ranges::all_of(word,
                         [broken](char ch) { return !broken[ch - 'a']; })) {
        ++cnt;
      }
    }
    return cnt;
  }
};