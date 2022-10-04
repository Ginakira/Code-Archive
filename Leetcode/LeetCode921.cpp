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
        int invalid_right = 0, remain_left = 0;
        for (char ch : s) {
            if (ch == '(') {
                ++remain_left;
                continue;
            }
            if (remain_left > 0) {
                --remain_left;
                continue;
            }
            ++invalid_right;
        }
        return invalid_right + remain_left;
    }
};