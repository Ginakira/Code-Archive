// LeetCode 2981 找出出现至少三次的最长特殊子字符串 I

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

// 暴力
class Solution {
   public:
    int maximumLength(string s) {
        int n = s.size();
        if (n < 3) {
            return -1;
        }
        int res = -1;
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            for (int i = n; i > 0; --i) {
                string pattern(i, ch);
                int cnt = 0;
                auto pos = s.find(pattern);
                while (pos != string::npos) {
                    ++cnt;
                    if (cnt >= 3) {
                        break;
                    }
                    pos = s.find(pattern, pos + 1);
                }
                if (cnt >= 3) {
                    res = max(res, i);
                    break;
                }
            }
        }
        return res;
    }
};

class Solution {
   public:
    int maximumLength(string s) {
        vector<int> groups[26];
        int cnt = 0, n = s.size();
        for (int i = 0; i < n; ++i) {
            ++cnt;
            if (i + 1 == n || s[i] != s[i + 1]) {
                groups[s[i] - 'a'].emplace_back(cnt);
                cnt = 0;
            }
        }
        int res = 0;
        for (auto &g : groups) {
            if (g.empty()) {
                continue;
            }
            ranges::sort(g, greater());
            g.emplace_back(0);
            g.emplace_back(0);
            res = max({res, g[0] - 2, min(g[0] - 1, g[1]), g[2]});
        }
        return res ? res : -1;
    }
};