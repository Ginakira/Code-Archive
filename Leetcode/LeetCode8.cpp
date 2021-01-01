// 每日一题 字符串转换整数（atoi）
#include <climits>
#include <string>
using namespace std;

class Solution {
   public:
    int myAtoi(string str) {
        // 去掉前多余空白
        size_t pos_begin = str.find_first_not_of(" ");
        if (pos_begin != string::npos) {
            str = str.substr(pos_begin);
        }

        // 判断有无符号
        int neg_flag = 0;
        if (str[0] == '-') {
            neg_flag = -1;
        } else if (str[0] == '+') {
            neg_flag = 1;
        }

        // 查找第一个不是数字的位置 将其截掉
        size_t pos_end = str.find_first_not_of("0123456789", abs(neg_flag));
        str = str.substr(abs(neg_flag), pos_end - abs(neg_flag));
        if (neg_flag == 0) neg_flag = 1;

        // 按位还原为数字
        long long ans = 0;
        for (char c : str) {
            ans = ans * 10 + c - '0';
            if (ans > INT_MAX) {
                return neg_flag == -1 ? INT_MIN : INT_MAX;
            }
        }

        return (int)ans * neg_flag;
    }
};

// Haizei 0ms
class Solution2 {
   public:
    int myAtoi(string s) {
        int pre_max = INT_MAX / 10, pre_d = INT_MAX % 10;
        int ind = 0, flag = 1, res = 0;
        while (s[ind] == ' ') ++ind;
        if (s[ind] == '-' || s[ind] == '+') {
            flag = s[ind] == '-' ? -1 : 1;
            ++ind;
        }
        while (isdigit(s[ind])) {
            if (res > pre_max || (res == pre_max && pre_d < s[ind] - '0')) {
                return flag == 1 ? INT_MAX : INT_MIN;
            }
            res *= 10;
            res += s[ind++] - '0';
        }
        return res * flag;
    }
};