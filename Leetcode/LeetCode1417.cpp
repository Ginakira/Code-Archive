// LeetCode 1417 重新格式化字符串

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    string reformat(string s) {
        int digit_cnt = 0, letter_cnt = 0, n = s.size();
        digit_cnt =
            count_if(s.begin(), s.end(), [](char c) { return isdigit(c); });
        letter_cnt = n - digit_cnt;
        if (abs(digit_cnt - letter_cnt) > 1) {
            return {};
        }
        bool flag = digit_cnt > letter_cnt;
        for (int i = 0, j = 1; i < n; i += 2) {
            if (isdigit(s[i]) != flag) {
                while (isdigit(s[j]) != flag) {
                    j += 2;
                }
                swap(s[i], s[j]);
            }
        }
        return s;
    }
};