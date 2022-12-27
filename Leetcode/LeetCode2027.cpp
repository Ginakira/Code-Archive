// LeetCode 2027 转换字符串的最少操作次数

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int minimumMoves(string s) {
        int n = s.size(), p = 0;
        int ans = 0;
        while (p < n) {
            ans += s[p] == 'X' ? 1 : 0;
            p += s[p] == 'X' ? 3 : 1;
        }
        return ans;
    }
};