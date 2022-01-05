// LeetCode 1576 替换所有的问号

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    string modifyString(string s) {
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] != '?') continue;
            for (char c = 'a'; c <= 'c'; ++c) {
                if ((i == 0 || s[i - 1] != c) &&
                    (i == n - 1 || s[i + 1] != c)) {
                    s[i] = c;
                    break;
                }
            }
        }
        return s;
    }
};