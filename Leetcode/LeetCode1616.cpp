// LeetCode 1616 分个两个字符串得到回文串

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   private:
    bool isPalindrome(const string &s, size_t start, size_t end) {
        size_t left = start, right = end;
        while (left < right && s[left] == s[right]) {
            ++left;
            --right;
        }
        return left >= right;
    }

    bool checkPalindromeFormation_helper(const string &a, const string &b) {
        size_t n = a.size(), left = 0, right = n - 1;
        while (left < right && a[left] == b[right]) {
            ++left;
            --right;
        }
        if (left >= right) {
            return true;
        }
        return isPalindrome(a, left, right) || isPalindrome(b, left, right);
    }

   public:
    bool checkPalindromeFormation(string a, string b) {
        return checkPalindromeFormation_helper(a, b) ||
               checkPalindromeFormation_helper(b, a);
    }
};