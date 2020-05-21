// 同构字符串
#include <iostream>
using namespace std;

// 一一对应的绑定关系
class Solution {
   public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        int s_code[256] = {0};  // s的字符i在t中绑定的对应字符
        int t_code[256] = {0};
        for (int i = 0; s[i]; ++i) {
            if (s_code[s[i]] == 0) {
                if (t_code[t[i]] != 0) return false;
                s_code[s[i]] = t[i];
                t_code[t[i]] = s[i];
            }
            int val = s_code[s[i]];
            if (val - t[i]) return false;
        }
        return true;
    }
};