// LeetCode 806 写字符串需要的行数

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int lines = 1, current = 0;
        for (auto ch : s) {
            int width = widths[ch - 'a'];
            if (current + width > 100) {
                ++lines;
                current = width;
            } else {
                current += width;
            }
        }
        return {lines, current};
    }
};