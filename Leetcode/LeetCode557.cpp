// LeetCode 557 反转字符串中的单词III
#include <sstream>
#include <string>
using namespace std;

// 双指针
class Solution {
   public:
    string reverseWords(string s) {
        string ret;
        int n = s.size();
        int start = 0, end = 0;
        while (end < n) {
            while (s[end] != ' ' && end < n) ++end;
            for (int i = end - 1; i >= start; --i) {
                ret.push_back(s[i]);
            }
            if (end != n) ret.push_back(' ');
            start = end = end + 1;
        }
        return ret;
    }
};

// STL
class Solution2 {
   public:
    string reverseWords(string s) {
        string ret, temp;
        stringstream ss(s);
        while (ss >> temp) {
            ret.push_back(' ');
            reverse(temp.begin(), temp.end());
            ret += temp;
        }
        return ret.substr(1, ret.size() - 1);
    }
};