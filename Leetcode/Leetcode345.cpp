// 反转字符串中的元音字母
#include <iostream>
using namespace std;

class Solution {
   public:
    bool is_valid(char ch) {
        if (ch < 97) ch += 32;
        switch (ch) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                return true;
        }
        return false;
    }

    string reverseVowels(string s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            while (i < j && !is_valid(s[i])) ++i;
            while (i < j && !is_valid(s[j])) --j;
            if (i >= j) break;
            swap(s[i], s[j]);
        }
        return s;
    }
};