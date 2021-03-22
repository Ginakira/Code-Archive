// 剑指 Offer 05. 替换空格
#include <string>
using namespace std;

class Solution {
   public:
    string replaceSpace(string s) {
        string ret;
        for (char &c : s) {
            if (c == ' ') {
                ret += "%20";
            } else {
                ret.push_back(c);
            }
        }
        return ret;
    }
};

// 原地
class Solution2 {
   public:
    string replaceSpace(string s) {
        int n = s.size();
        int blank_count = 0;
        for (char &c : s) {
            if (c == ' ') ++blank_count;
        }
        s.resize(n + blank_count * 2);
        for (int i = n - 1, j = s.size() - 1; i != j;) {
            if (s[i] == ' ') {
                s[j] = '0';
                s[j - 1] = '2';
                s[j - 2] = '%';
                j -= 2;
            } else {
                s[j] = s[i];
            }
            --i;
            --j;
        }
        return s;
    }
};