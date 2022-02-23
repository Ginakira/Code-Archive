// LeetCode 917 仅仅反转字母

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    string reverseOnlyLetters(string s) {
        size_t n = s.size();
        int l = 0, r = n - 1;
        while (l < r) {
            while (l < n && !isalpha(s[l])) {
                ++l;
            }
            while (r >= 0 && !isalpha(s[r])) {
                --r;
            }
            if (l >= r) break;
            swap(s[l], s[r]);
            ++l, --r;
        }
        return s;
    }
};