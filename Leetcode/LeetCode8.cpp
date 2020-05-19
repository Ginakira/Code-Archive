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

// Haizei
class Solution {
   public:
    int myAtoi(string str) {
        int flag = 1, num = 0, i = 0, pre_max = INT_MAX / 10, d = INT_MAX % 10;
        while (str[i] == ' ') ++i;
        if (str[i] == '-')
            flag = -1, ++i;
        else if (str[i] == '+')
            flag = 1, ++i;
        while (str[i]) {
            if (str[i] < '0' || str[i] > '9') break;
            if (num > pre_max || (num == pre_max && (str[i] - '0') > d)) {
                return flag == 1 ? INT_MAX : INT_MIN;
            }
            num = num * 10 + (str[i] - '0');
            ++i;
        }
        return flag * num;
    }
};
