// LeetCode 224. 基本计算器
#include <stack>
#include <string>
using namespace std;

// 括号展开
class Solution {
   public:
    int calculate(string s) {
        stack<int> ops;
        ops.push(1);
        int n = s.size();
        int ret = 0;
        int i = 0;
        int sign = 1;
        while (i < n) {
            switch (s[i]) {
                case ' ': {
                    ++i;
                    break;
                }
                case '+': {
                    sign = ops.top();
                    ++i;
                    break;
                }
                case '-': {
                    sign = -ops.top();
                    ++i;
                    break;
                }
                case '(': {
                    ops.push(sign);
                    ++i;
                    break;
                }
                case ')': {
                    ops.pop();
                    ++i;
                    break;
                }
                default: {
                    int num = 0;
                    while (i < n && isdigit(s[i])) {
                        num = num * 10 + (s[i] - '0');
                        ++i;
                    }
                    ret += sign * num;
                }
            }
        }
        return ret;
    }
};