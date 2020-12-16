// 单词规律
#include <iostream>
#include <sstream>
#include <unordered_map>
using namespace std;

// 一一绑定问题
class Solution {
   public:
    string getNext(string &s, int &i) {
        while (s[i] == ' ') ++i;
        string ret = "";
        while (s[i] && s[i] != ' ') {
            ret += s[i++];
        }
        return ret;
    }

    bool wordPattern(string p, string s) {
        string p_code[256], temp;
        unordered_map<string, char> s_code;
        int ind = 0;
        for (int i = 0; p[i]; ++i) {
            temp = getNext(s, ind);
            if (temp == "") return false;
            if (p_code[p[i]] == "") {
                if (s_code.find(temp) != s_code.end()) return false;
                p_code[p[i]] = temp;
                s_code[temp] = p[i];
            }
            if (p_code[p[i]] != temp) return false;
        }
        if (s[ind]) return false;
        return true;
    }
};

// 更简洁的写法
class Solution2 {
   public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, char> smap;
        unordered_map<char, string> pmap;
        stringstream ss(s);
        int ind = 0;
        string cur;
        while (ss >> cur) {
            if (ind >= pattern.size()) return false;
            if (smap.find(cur) == smap.end() &&
                pmap.find(pattern[ind]) == pmap.end()) {
                smap[cur] = pattern[ind];
                pmap[pattern[ind]] = cur;
            } else {
                if (smap[cur] != pattern[ind] || pmap[pattern[ind]] != cur)
                    return false;
            }
            ind++;
        }
        return ind == pattern.size();
    }
};