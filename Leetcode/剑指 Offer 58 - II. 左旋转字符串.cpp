// 剑指 Offer 58 - II. 左旋转字符串

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    string reverseLeftWords(string s, int n) {
        int len = s.size();
        n %= len;
        reverse(s.begin(), s.end());
        reverse(s.begin(), s.begin() + len - n);
        reverse(s.begin() + len - n, s.end());
        return s;
    }
};