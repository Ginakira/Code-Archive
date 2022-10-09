// LeetCode 856 括号的分数

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   private:
    int scoreOfParentheses(const string &s, int start, int end) {
        if (end - start == 1) {
            return 1;
        }
        int cnt = 0, mark = -1;
        for (int i = start; i <= end; ++i) {
            cnt += s[i] == '(' ? 1 : -1;
            if (cnt == 0) {
                mark = i;
                break;
            }
        }
        if (mark == end) {
            return 2 * scoreOfParentheses(s, start + 1, end - 1);
        } else {
            return scoreOfParentheses(s, start, mark) +
                   scoreOfParentheses(s, mark + 1, end);
        }
    }

   public:
    int scoreOfParentheses(string s) {
        return scoreOfParentheses(s, 0, s.size() - 1);
    }
};