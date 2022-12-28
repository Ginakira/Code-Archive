// LeetCode 1750 删除字符串两端相同字符后的最短长度

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int minimumLength(string s) {
        int n = s.size();
        int left = 0, right = n - 1;
        while (left < right) {
            char cur = s[left];
            if (s[right] != cur) break;
            while (s[left] == cur && left <= right) ++left;
            while (s[right] == cur && left <= right) --right;
        }
        return right - left + 1;
    }
};