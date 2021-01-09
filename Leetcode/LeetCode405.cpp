// LeetCode 405 数字转换为十六进制数
#include <string>
using namespace std;

class Solution {
   public:
    string toHex(int num) {
        if (num == 0) return "0";
        string hex = "0123456789abcdef", ans = "";
        while (num && ans.size() < 8) {
            // num & 0x0000000f 获取最后四位（二进制）
            ans = hex[num & 0xf] + ans;
            num >>= 4;
        }
        return ans;
    }
};