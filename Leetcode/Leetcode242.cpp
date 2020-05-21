// 有效的字母异位词
#include <iostream>
using namespace std;

class Solution {
   public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int code[256] = {0};
        for (char c : s) code[c] += 1;
        for (char c : t) {
            if (code[c] == 0) return false;
            code[c] -= 1;
        }
        return true;
    }
};