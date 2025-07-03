// LeetCode 3304 找出第 K 个字符 I

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
  char kthCharacter(int k) {
    string word = "a";
    while (word.size() < k) {
      string temp;
      for (auto ch : word) {
        temp.push_back('a' + (ch + 1 - 'a') % 26);
      }
      word += temp;
    }
    return word[k - 1];
  }
};