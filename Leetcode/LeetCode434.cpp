// LeetCode 434 字符串中的单词数
#include <string>
using namespace std;

class Solution {
   public:
    int countSegments(string s) {
        if (s == "") return 0;
        int n = s.size();
        s += " ";
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] != ' ' && s[i + 1] == ' ') ++cnt;
        }
        return cnt;
    }
};

class Solution2 {
   public:
    int countSegments(string s) {
        int ind = 0, n = s.size();
        int word_count = 0;
        while (ind < n) {
            bool flag = false;
            while (ind < n && isblank(s[ind])) ++ind;
            while (ind < n && !isblank(s[ind])) {
                flag = true;
                ++ind;
            }
            if (flag) {
                ++word_count;
            }
        }
        return word_count;
    }
};