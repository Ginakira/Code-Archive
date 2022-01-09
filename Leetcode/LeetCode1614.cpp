// LeetCode 1614 括号的最大嵌套深度

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int maxDepth(string s) {
        int max_depth = 0, depth = 0;
        for (char c : s) {
            if (c == '(') {
                ++depth;
            } else if (c == ')') {
                --depth;
            }
            max_depth = max(max_depth, depth);
        }
        return max_depth;
    }
};