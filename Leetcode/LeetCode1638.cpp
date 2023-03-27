// LeetCode 1638 统计只差一个字符的子串个数

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int countSubstrings(string s, string t) {
        int n = s.size(), m = t.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int diff = 0;
                for (int len = 0; i + len < n && j + len < m; ++len) {
                    diff += s[i + len] == t[j + len] ? 0 : 1;
                    if (diff > 1) {
                        break;
                    } else if (diff == 1) {
                        ++ans;
                    }
                }
            }
        }
        return ans;
    }
};