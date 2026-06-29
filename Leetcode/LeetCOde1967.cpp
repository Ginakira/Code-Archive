// LeetCode 1967 作为子字符串出现在单词中的字符串数目

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
  int numOfStrings(vector<string>& patterns, string word) {
    return ranges::count_if(patterns, [&word](const string& pattern) {
      return word.find(pattern) != string::npos;
    });
  }
};