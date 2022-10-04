// LeetCode 921 使括号有效的最少添加

#include <algorithm>
#include <numeric>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int minAddToMakeValid(string s) {
        stack<char> stk;
        int invalid_right = 0;
        for (char ch : s) {
            if (ch == '(') {
                stk.push(ch);
                continue;
            }
            if (!stk.empty()) {
                stk.pop();
                continue;
            }
            ++invalid_right;
        }
        return invalid_right + stk.size();
    }
};