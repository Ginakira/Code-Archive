// LeetCode 520 检测大写字母
#include <string>
using namespace std;

class Solution {
   public:
    bool detectCapitalUse(string word) {
        int lowerCnt = 0, upperCnt = 0, n = word.size();
        for (const char &c : word) {
            if (islower(c)) {
                ++lowerCnt;
            } else {
                ++upperCnt;
            }
        }
        if (lowerCnt == n || upperCnt == n) return true;
        return upperCnt == 1 && isupper(word[0]);
    }
};