// LeetCode 678 有效的括号字符串

#include <algorithm>
#include <numeric>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    bool checkValidString(string s) {
        stack<int> left_stk;
        stack<int> asterisk_stk;
        int n = s.size();

        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                left_stk.push(i);
            } else if (s[i] == ')') {
                if (!left_stk.empty()) {
                    left_stk.pop();
                } else if (!asterisk_stk.empty()) {
                    asterisk_stk.pop();
                } else {
                    return false;
                }
            } else if (s[i] == '*') {
                asterisk_stk.push(i);
            }
        }

        while (!left_stk.empty() && !asterisk_stk.empty()) {
            int left_ind = left_stk.top(), asterisk_ind = asterisk_stk.top();
            left_stk.pop();
            asterisk_stk.pop();
            if (left_ind > asterisk_ind) {
                return false;
            }
        }

        return left_stk.empty();
    }
};