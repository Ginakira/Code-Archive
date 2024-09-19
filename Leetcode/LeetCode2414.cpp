// LeetCode 2414 最长的字母序连续子字符串

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
    int longestContinuousSubstring(string s) {
        int n = s.size();
        int cur = 1;
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            if (s[i] != s[i - 1] + 1) {
                ans = max(ans, cur);
                cur = 1;
                continue;
            }
            ++cur;
        }
        return max(ans, cur);
    }
};