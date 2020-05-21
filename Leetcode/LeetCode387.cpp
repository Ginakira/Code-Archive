// 字符串中的第一个唯一字符
#include <iostream>
using namespace std;

class Solution {
   public:
    int firstUniqChar(string s) {
        int code[256] = {0};
        for (char c : s) code[c]++;
        for (int i = 0; s[i]; ++i) {
            if (code[s[i]] == 1) return i;
        }
        return -1;
    }
};