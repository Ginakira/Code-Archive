// LeetCode 1190. 反转每对括号间的子串
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 栈 + 队列
class Solution {
   public:
    string reverseParentheses(string s) {
        stack<char> stk;
        queue<char> temp;
        for (char c : s) {
            if (c != ')') {
                stk.push(c);
                continue;
            }
            while (stk.top() != '(') {
                temp.push(stk.top());
                stk.pop();
            }
            stk.pop();  // '('
            while (!temp.empty()) {
                stk.push(temp.front());
                temp.pop();
            }
        }
        string result;
        while (!stk.empty()) {
            result = stk.top() + result;
            stk.pop();
        }
        return result;
    }
};

// 栈
class Solution2 {
   public:
    string reverseParentheses(string s) {
        stack<string> stk;
        string str;
        for (char &c : s) {
            if (c == '(') {
                stk.push(str);
                str = "";
            } else if (c == ')') {
                reverse(str.begin(), str.end());
                str = stk.top() + str;
                stk.pop();
            } else {
                str.push_back(c);
            }
        }
        return str;
    }
};