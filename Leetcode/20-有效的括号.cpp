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