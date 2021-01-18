// LeetCode 504 七进制数
#include <string>
using namespace std;

// 递归法
class Solution {
   public:
    string convertToBase7(int num) {
        if (num < 0) return '-' + convertToBase7(num * -1);
        if (num < 7) return to_string(num);
        return convertToBase7(num / 7) + to_string(num % 7);
    }
};

// 普通法 模M取余
class Solution2 {
   public:
    string convertToBase7(int num) {
        bool neg = false;
        if (num < 0) {
            neg = true;
            num = -num;
        }
        string ans = "";
        do {
            ans = char('0' + num % 7) + ans;
            num /= 7;
        } while (num);
        return neg ? "-" + ans : ans;
    }
};