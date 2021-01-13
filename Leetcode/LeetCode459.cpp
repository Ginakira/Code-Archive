// LeetCode 459 重复的子字符串
#include <string>
using namespace std;

// https://leetcode-cn.com/problems/repeated-substring-pattern/solution/tu-jie-yi-xia-shuang-bei-zi-fu-chuan-de-jie-fa-by-/
class Solution {
   public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).find(s, 1) != s.size();
    }
};