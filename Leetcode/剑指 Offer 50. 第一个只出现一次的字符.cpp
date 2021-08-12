// 剑指 Offer 50. 第一个只出现一次的字符

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    char firstUniqChar(string s) {
        vector<int> mark(26);
        for (char c : s) {
            ++mark[c - 'a'];
        }
        for (char c : s) {
            if (mark[c - 'a'] == 1) {
                return c;
            }
        }
        return ' ';
    }
};