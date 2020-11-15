// LeetCode 402 移掉K位数字
#include <string>
#include <vector>
using namespace std;

// 单调栈 注意考虑第一次循环完后 k 还有剩余的情况
class Solution {
   public:
    string removeKdigits(string num, int k) {
        vector<char> s;
        for (auto& digit : num) {
            while (s.size() > 0 && s.back() > digit && k > 0) {
                s.pop_back(), k--;
            }
            s.push_back(digit);
        }
        for (; k > 0; --k) {
            s.pop_back();
        }
        string ans = "";
        bool is_leading_zero = true;
        for (auto& digit : s) {
            if (digit == '0' && is_leading_zero) {
                continue;
            }
            is_leading_zero = false;
            ans += digit;
        }
        return ans == "" ? "0" : ans;
    }
};