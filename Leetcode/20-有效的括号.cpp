#include <map>
#include <stack>
#include <string>
using namespace std;

class Solution {
   public:
    bool isValid(string s) {
        stack<char> bracket;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                bracket.push(s[i]);
            } else {
                if (bracket.empty())
                    return false;
                else if (s[i] - bracket.top() == 1 ||
                         s[i] - bracket.top() == 2) {
                    bracket.pop();
                } else
                    return false;
            }
        }
        return bracket.empty();
    }
};

//使用map进一步简化代码
class Solution2 {
   public:
    bool isValid(string s) {
        stack<char> match;
        map<char, char> brackets = {{')', '('}, {'}', '{'}, {']', '['}};
        for (auto &i : s) {
            if (brackets.count(i)) {
                if (!match.empty() && match.top() == brackets[i])
                    match.pop();
                else
                    return false;
            } else {
                match.push(i);
            }
        }
        return match.empty();
    }
};

// C语言版
bool isValid(char *s) {
    int len = strlen(s);
    char *stack = (char *)malloc(sizeof(char) * len);
    int top = -1, flag = 1;
    while (s[0]) {
        switch (s[0]) {
            case '(':
            case '[':
            case '{':
                stack[++top] = s[0];
                break;
            case ')':
                flag = (top != -1 && stack[top--] == '(');
                break;
            case ']':
                flag = (top != -1 && stack[top--] == '[');
                break;
            case '}':
                flag = (top != -1 && stack[top--] == '{');
                break;
        }
        if (!flag) break;
        s++;
    }
    free(stack);
    return (flag && top == -1);
}