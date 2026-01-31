// LeetCode 744 寻找比目标字母大的最小字母

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        sort(letters.begin(), letters.end());
        auto it = upper_bound(letters.begin(), letters.end(), target);
        return it == letters.end() ? letters[0] : *it;
    }
};

class Solution2 {
 public:
  char nextGreatestLetter(vector<char>& letters, char target) {
    auto it = ranges::upper_bound(letters, target);
    return it == letters.end() ? letters[0] : *it;
  }
};