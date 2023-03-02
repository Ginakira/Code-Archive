// 面试题 05.02. 二进制数转字符串

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    string printBin(double num) {
        string ans = "0.";
        while (ans.size() <= 32 && num != 0) {
            num *= 2;
            int digit = num;
            ans += digit + '0';
            num -= digit;
        }
        return ans.size() <= 32 ? ans : "ERROR";
    }
};