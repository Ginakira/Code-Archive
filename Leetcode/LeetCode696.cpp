// LeetCode 696 计数二进制子串

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
    int countBinarySubstrings(string s) {
        int n = s.size();
        int ans = 0;
        int cur = 0, pre = 0;
        for (int i = 0; i < n; ++i) {
            ++cur;
            if (i == n - 1 || s[i] != s[i + 1]) {
                ans += min(cur, pre);
                pre = cur;
                cur = 0;
            }
        }
        return ans;
    }
};