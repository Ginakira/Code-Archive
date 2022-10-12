// 同构字符串
#include <iostream>
#include <unordered_map>
using namespace std;

// 一一对应的绑定关系 4ms
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

// unordered_map 24ms
class Solution2 {
   public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> s_mp, t_mp;
        if (s.size() != t.size()) return false;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s_mp.find(s[i]) == s_mp.end() &&
                t_mp.find(t[i]) == t_mp.end()) {
                s_mp[s[i]] = t[i];
                t_mp[t[i]] = s[i];
            } else if (s_mp[s[i]] != t[i] || t_mp[t[i]] != s[i]) {
                return false;
            }
        }
        return true;
    }
};