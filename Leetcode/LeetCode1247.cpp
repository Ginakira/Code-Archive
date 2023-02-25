// LeetCode 1247 交换字符使得字符串相同

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int minimumSwap(string s1, string s2) {
        int xy_diff = 0, yx_diff = 0;
        int n = s1.size();
        for (int i = 0; i < n; ++i) {
            if (s1[i] == s2[i]) {
                continue;
            }
            if (s1[i] == 'x' && s2[i] == 'y') {
                ++xy_diff;
            } else {
                ++yx_diff;
            }
        }
        if ((xy_diff + yx_diff) & 1) {
            return -1;
        }
        return xy_diff / 2 + yx_diff / 2 + xy_diff % 2 + yx_diff % 2;
    }
};