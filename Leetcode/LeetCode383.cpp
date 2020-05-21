// 赎金信

#include <iostream>
using namespace std;

class Solution {
   public:
    bool canConstruct(string ransomNote, string magazine) {
        int code[256] = {0};
        for (char c : magazine) code[c]++;
        for (char c : ransomNote) {
            if (code[c] == 0) return false;
            code[c]--;
        }
        return true;
    }
};