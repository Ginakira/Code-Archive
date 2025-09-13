// LeetCode 3541 找到频率最高的元音和辅音

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
  int maxFreqSum(string s) {
    array<int, 26> cnt{0};
    int max_vowel = 0, max_consonant = 0;
    for (char c : s) {
      ++cnt[c - 'a'];
    }
    for (int i = 0; i < cnt.size(); ++i) {
      char c = 'a' + i;
      if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        max_vowel = max(max_vowel, cnt[i]);
      } else {
        max_consonant = max(max_consonant, cnt[i]);
      }
    }
    return max_vowel + max_consonant;
  }
};