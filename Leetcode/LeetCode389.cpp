// LeetCode 389 找不同
#include <string>
using namespace std;

// 常规解法 标记次数
class Solution {
   public:
    char findTheDifference(string s, string t) {
        int mark[26] = {0};
        for (const char &c : s) ++mark[c - 'a'];
        for (const char &c : t) {
            if (mark[c - 'a'] == 0) return c;
            --mark[c - 'a'];
        }
        return 0;
    }
};

// 计算ASCII码和 相减即为多出的那一位
class Solution2 {
   public:
    char findTheDifference(string s, string t) {
        int sum_s = 0, sum_t = 0;
        for (const char &c : s) sum_s += (int)c;
        for (const char &c : t) sum_t += (int)c;
        return sum_t - sum_s;
    }
};

// 位运算
class Solution3 {
   public:
    char findTheDifference(string s, string t) {
        char ret = 0;
        for (const char &c : s) ret ^= c;
        for (const char &c : t) ret ^= c;
        return ret;
    }
};