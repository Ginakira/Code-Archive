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