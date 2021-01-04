// LeetCode 171 Excel表列序号
#include <string>
using namespace std;

// 兄弟题目LC168
class Solution {
   public:
    int titleToNumber(string s) {
        long long base = 1, ans = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            ans += (s[i] - 'A' + 1) * base;
            base *= 26;
        }
        return ans;
    }
};