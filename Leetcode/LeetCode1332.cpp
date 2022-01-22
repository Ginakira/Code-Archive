// LeetCode 1332 删除回文子序列

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int removePalindromeSub(string s) {
        size_t n = s.size();
        size_t left = 0, right = n - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                return 2;
            }
            ++left, --right;
        }
        return 1;
    }
};