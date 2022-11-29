// LeetCode 1758 生成交替二进制字符串的最少操作数

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   private:
    int cnt_change(const string &s, int start) {
        int cnt = 0;
        for (char c : s) {
            if (c != start + '0') {
                ++cnt;
            }
            start = !start;
        }
        return cnt;
    }

   public:
    int minOperations(string s) {
        int n = s.size();
        int zero_start_ops = cnt_change(s, 0);
        return min(zero_start_ops, n - zero_start_ops);
    }
};