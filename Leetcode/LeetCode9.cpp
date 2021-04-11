// LeetCode 9 回文数
#include <string>
using namespace std;

// 使用字符串
class Solution {
   public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        string s;
        while (x) {
            s.push_back(x % 10 + '0');
            x /= 10;
        }
        string rev = s;
        reverse(s.begin(), s.end());
        return rev == s;
    }
};

// 使用数学方法反转后半部分
class Solution2 {
   public:
    bool isPalindrome(int x) {
        if (x < 0 || (x != 0 && x % 10 == 0)) {
            return false;
        }
        int reversed_number = 0;
        while (reversed_number < x) {
            reversed_number = reversed_number * 10 + x % 10;
            x /= 10;
        }
        return reversed_number == x || reversed_number / 10 == x;
    }
};