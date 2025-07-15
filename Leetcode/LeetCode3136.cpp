// LeetCode 3136 有效单词

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
  bool isValid(string word) {
    auto is_vowel = [](char c) {
      return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    };
    if (word.size() < 3) {
      return false;
    }
    bool has_vowel = false;
    bool has_consonant = false;
    for (char ch : word) {
      if (isalpha(ch)) {
        if (is_vowel(tolower(ch))) {
          has_vowel = true;
        } else {
          has_consonant = true;
        }
      } else if (!isdigit(ch)) {
        return false;
      }
    }
    return has_vowel && has_consonant;
  }
};