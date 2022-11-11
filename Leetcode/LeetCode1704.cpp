// LeetCode 1704 判断字符串的两半是否相似

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   private:
   public:
    bool halvesAreAlike(string s) {
        size_t n = s.size() >> 1;
        auto is_vowel = [](char ch) {
            switch (tolower(ch)) {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    return true;
                default:
                    return false;
            }
        };
        return count_if(s.begin(), s.begin() + n, is_vowel) ==
               count_if(s.begin() + n, s.end(), is_vowel);
    }
};