// 剑指 Offer 67. 把字符串转换成整数
#include <algorithm>
#include <climits>
#include <limits>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int strToInt(string s) {
        int n = s.size();
        int ind = 0;
        // 去除空白符
        while (ind < n && s[ind] == ' ') ++ind;
        // 处理可能存在的正负号
        int flag = 1;
        int result = 0;
        if (ind < n && (s[ind] == '+' || s[ind] == '-')) {
            flag = s[ind] == '-' ? -1 : 1;
            ++ind;
        }
        // 处理数字
        const int MAX_MOD = INT_MAX / 10, MAX_DIGIT = INT_MAX % 10;
        const int MIN_MOD = abs(INT_MIN / 10), MIN_DIGIT = abs(INT_MIN % 10);
        while (ind < n && isdigit(s[ind])) {
            int digit = s[ind] - '0';
            if (flag == 1) {
                if (result > MAX_MOD ||
                    (result == MAX_MOD && digit >= MAX_DIGIT)) {
                    return INT_MAX;
                }
            } else {
                if (result > MIN_MOD ||
                    (result == MIN_MOD && digit >= MIN_DIGIT)) {
                    return INT_MIN;
                }
            }
            result = result * 10 + digit;
            ++ind;
        }
        return result * flag;
    }
};
