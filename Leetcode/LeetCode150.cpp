// LeetCode 150 逆波兰表达式求值
#include <string>
#include <vector>
using namespace std;
class Solution {
   public:
    inline bool is_op(string &s) {
        return s == "+" || s == "-" || s == "*" || s == "/";
    }

    int calc(int lhs, int rhs, char op) {
        switch (op) {
            case '+':
                return lhs + rhs;
            case '-':
                return lhs - rhs;
            case '*':
                return lhs * rhs;
            case '/':
                return lhs / rhs;
            default:
                return 0;
        }
        return 0;
    }

    int evalRPN(vector<string> &tokens) {
        vector<int> stk;
        for (auto &token : tokens) {
            if (!is_op(token)) {
                stk.emplace_back(stoi(token));
                continue;
            }
            int result =
                calc(stk[stk.size() - 2], stk[stk.size() - 1], token[0]);
            stk.pop_back();
            stk.back() = result;
        }
        return stk.back();
    }
};