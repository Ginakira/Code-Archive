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