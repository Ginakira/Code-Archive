// LeetCode 400 第N位数字
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;


// 长度为len的数字有10^(len - 1)个
// 所以计算出最终的答案会落到哪个数字上即可
class Solution {
   public:
    int findNthDigit(int n) {
        int len = 1;
        while (len * 9 * pow(10, len - 1) < n) {
            n -= len * 9 * pow(10, len - 1);
            ++len;
        }
        int start = pow(10, len - 1);
        int num = start + n / len - 1;
        return (n % len == 0 ? to_string(num)[len - 1]
                             : to_string(num + 1)[n % len - 1]) -
               '0';
    }
};