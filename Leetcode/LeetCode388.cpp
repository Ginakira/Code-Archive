// LeetCode 388 文件的最长绝对路径

#include <algorithm>
#include <numeric>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int lengthLongestPath(string input) {
        size_t pos = 0, n = input.size();
        stack<int> stk;
        int max_len = 0;
        while (pos < n) {
            int depth = 1;
            while (pos < n && input[pos] == '\t') {
                ++depth;
                ++pos;
            }
            while (depth <= stk.size()) {
                stk.pop();
            }
            int len = 0;
            bool is_filename = false;
            while (pos < n && input[pos] != '\n') {
                if (input[pos] == '.') {
                    is_filename = true;
                }
                ++pos;
                ++len;
            }
            ++pos;  // skip '\n'
            if (!stk.empty()) {
                len += stk.top() + 1;
            }
            if (is_filename) {
                max_len = max(max_len, len);
            } else {
                stk.emplace(len);
            }
        }
        return max_len;
    }
};