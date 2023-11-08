// LeetCode 2609 最长平衡子字符串

#include <algorithm>
#include <array>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    int findTheLongestBalancedSubstring(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n;) {
            int zero_cnt = 0, one_cnt = 0;
            while (i < n && s[i] == '0') {
                ++i;
                ++zero_cnt;
            }
            while (i < n && s[i] == '1') {
                ++i;
                ++one_cnt;
            }
            ans = max(ans, min(zero_cnt, one_cnt) * 2);
        }
        return ans;
    }
};
