// 每日一题 最长回文串
#include <string>
using namespace std;

class Solution {
   public:
    int longestPalindrome(string s) {
        int ans = 0, mark[60] = {0}, single = 0;
        for (char c : s) mark[c - 'A']++;
        for (int i = 0; i < 60; ++i) {
            if (mark[i] & 1) {
                ans += mark[i] - 1;
                single = 1;
            } else {
                ans += mark[i];
            }
        }
        return ans + single;
    }
};