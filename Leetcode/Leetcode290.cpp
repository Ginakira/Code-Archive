// 单词规律
#include <iostream>
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