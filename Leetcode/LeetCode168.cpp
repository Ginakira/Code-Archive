// LeetCode 168 Excel表列名称
#include <string>
using namespace std;

// 类26进制，但没有0，所以如果取余为0时应借一位使余数为26
class Solution {
   public:
    string convertToTitle(int n) {
        string s = "";
        while (n) {
            int dig = n % 26;
            if (dig == 0) {
                dig = 26;
                --n;
            }
            s = char('A' + dig - 1) + s;
            n /= 26;
        }
        return s;
    }
};

// 看作是0-25的26进制，将1映射为0，2映射为1....，递归计算时余数应加回来
class Solution2 {
   public:
    string convertToTitle(int columnNumber) {
        --columnNumber;
        if (columnNumber < 26) {
            return string(1, 'A' + columnNumber);
        }
        return convertToTitle(columnNumber / 26) +
               convertToTitle(columnNumber % 26 + 1);
    }
};