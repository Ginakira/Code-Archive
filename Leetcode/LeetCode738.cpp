// LeetCode 738 单调递增的数字
#include <string>
using namespace std;

// 贪心 从右向左扫描 遇到当前位比左面位大的
// 将左面位减一 本位及右面所有位全变为9
class Solution {
   public:
    int monotoneIncreasingDigits(int N) {
        string s = to_string(N);
        for (int i = s.size() - 1; i > 0; --i) {
            if (s[i] < s[i - 1]) {
                --s[i - 1];
                for (int j = i; j < s.size(); ++j) s[j] = '9';
            }
        }
        return stoi(s);
    }
};