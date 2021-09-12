// 每日一题 翻转字符串里的单词
#include <sstream>
#include <string>
using namespace std;

class Solution {
   public:
    string reverseWords(string s) {
        stringstream ss;
        ss << s;
        string temp, ans;
        int cnt = 0;
        while (ss >> temp) {
            if (cnt++) temp += ' ';
            ans = temp + ans;
        }
        return ans;
    }
};

// 原地
class Solution2 {
   public:
    string reverseWords(string s) {
        int n = s.size();
        reverse(s.begin(), s.end());

        int ind = 0;
        for (int start = 0; start < n; ++start) {
            if (s[start] == ' ') continue;
            if (ind != 0) {
                s[ind++] = ' ';
            }
            int end = start;
            while (end < n && s[end] != ' ') {
                s[ind++] = s[end++];
            }
            reverse(s.begin() + ind - (end - start), s.begin() + ind);

            start = end;
        }

        s.erase(s.begin() + ind, s.end());
        return s;
    }
};