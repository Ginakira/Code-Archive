// 字符串的最大公因子
#include <numeric>
#include <string>
using namespace std;

// 构造子串 判等 24ms
class Solution {
   public:
    bool is_divided(string divisor, string s1, string s2) {
        string tmp = "";
        int dn = divisor.length(), n1 = s1.length() / dn, n2 = s2.length() / dn;
        if (n1 * dn != s1.length() || n2 * dn != s2.length()) return false;
        for (int i = 0; i < n1; ++i) tmp += divisor;
        if (tmp != s1) return false;
        for (int i = 0; i < n2 - n1; ++i) tmp += divisor;
        return tmp == s2;
    }

    string gcdOfStrings(string str1, string str2) {
        if (str1.length() > str2.length()) swap(str1, str2);
        string ans = "", divisor = "";
        for (int i = str1.length(); i > 0; --i) {
            divisor = str1.substr(0, i);
            if (is_divided(divisor, str1, str2)) {
                ans = divisor;
                break;
            }
        }
        return ans;
    }
};

// 先判断是否能够被整除 然后截取最大公约数长度的子串即可 4ms
class Solution2 {
   public:
    string gcdOfStrings(string str1, string str2) {
        return (str1 + str2 == str2 + str1)
                   ? str1.substr(0, gcd(str1.length(), str2.length()))
                   : "";
    }
};