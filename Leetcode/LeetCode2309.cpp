// LeetCode 2309 兼具大小写的最好英文字母

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    string greatestLetter(string s) {
        unordered_set<char> us(s.begin(), s.end());
        for (int i = 25; i >= 0; --i) {
            if (us.count('a' + i) && us.count('A' + i)) {
                return {char('A' + i)};
            }
        }
        return {};
    }
};

class Solution2 {
   public:
    string greatestLetter(string s) {
        uint32_t upper_flag = 0, lower_flag = 0;
        for (auto ch : s) {
            if (islower(ch)) {
                lower_flag |= (1 << (ch - 'a'));
            } else {
                upper_flag |= (1 << (ch - 'A'));
            }
        }
        for (int i = 25; i >= 0; --i) {
            if (upper_flag & lower_flag & (1 << i)) {
                return string(1, 'A' + i);
            }
        }
        return {};
    }
};