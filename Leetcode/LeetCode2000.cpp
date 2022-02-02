// LeetCode 2000 反转单词前缀

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    string reversePrefix(string word, char ch) {
        auto pos = word.find(ch);
        if (pos != string::npos) {
            reverse(word.begin(), word.begin() + pos + 1);
        }
        return word;
    }
};