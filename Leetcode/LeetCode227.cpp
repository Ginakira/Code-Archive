// LeetCode 227 基本计算器II
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 单栈 记录上次运算符
class Solution {
   public:
    int calculate(string s) {
        int n = s.size();
        vector<int> stk;
        char pre_sign = '+';
        for (int i = 0, current_num = 0; i < n; ++i) {
            if (isdigit(s[i])) {
                current_num = current_num * 10 + (s[i] - '0');
            }
            if ((!isdigit(s[i]) && s[i] != ' ') || i == n - 1) {
                switch (pre_sign) {
                    case '+': {
                        stk.push_back(current_num);
                        break;
                    }
                    case '-': {
                        stk.push_back(-current_num);
                        break;
                    }
                    case '*': {
                        stk.back() *= current_num;
                        break;
                    }
                    case '/': {
                        stk.back() /= current_num;
                        break;
                    }
                    default:
                        break;
                }
                pre_sign = s[i];
                current_num = 0;
            }
        }
        return accumulate(stk.begin(), stk.end(), 0);
    }
};

// 双栈版
class Solution2 {
   private:
    unordered_map<char, int> priority = {
        {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
    vector<int> nums;
    vector<char> ops;

    int calc() {
        if (nums.empty() || ops.empty()) return -1;
        int rhs = nums.back();
        nums.pop_back();
        int lhs = nums.back();
        nums.pop_back();
        char op = ops.back();
        ops.pop_back();
        switch (op) {
            case '+':
                return lhs + rhs;
            case '-':
                return lhs - rhs;
            case '*':
                return lhs * rhs;
            case '/':
                return lhs / rhs;
        }
        return 0;
    }

   public:
    int calculate(string s) {
        int n = s.size();
        int i = 0;
        nums.push_back(0);

        while (i < n) {
            if (s[i] == ' ') {
                ++i;
                continue;
            }
            if (isdigit(s[i])) {
                int num = 0;
                while (i < n && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    ++i;
                }
                nums.push_back(num);
            } else {
                while (!ops.empty() && priority[s[i]] <= priority[ops.back()]) {
                    nums.push_back(calc());
                }
                ops.push_back(s[i]);
                ++i;
            }
        }

        while (!ops.empty()) {
            nums.push_back(calc());
        }
        return nums.back();
    }
};