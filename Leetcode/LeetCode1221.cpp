// LeetCode 1221 分割平衡字符串

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int balancedStringSplit(string s) {
        int n = s.size();
        int ind = 0, count = 0;
        int l_count = 0, r_count = 0;
        while (ind < n) {
            if (s[ind] == 'L') {
                ++l_count;
            } else {
                ++r_count;
            }
            if (l_count == r_count) {
                ++count;
                l_count = r_count = 0;
            }
            ++ind;
        }
        return count;
    }
};