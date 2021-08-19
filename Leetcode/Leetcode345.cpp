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

// 双指针
class Solution2 {
   public:
    string reverseVowels(string s) {
        int n = s.size();
        auto is_vowel = [](char c) {
            if (c >= 'A' && c <= 'Z') c += 32;
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };

        int left = 0, right = n - 1;
        while (left < right) {
            while (left < n && !is_vowel(s[left])) ++left;
            while (right >= 0 && !is_vowel(s[right])) --right;
            if (left >= right) break;
            swap(s[left], s[right]);
            ++left, --right;
        }
        return s;
    }
};