// LeetCode 2982 找出出现至少三次的最长特殊子字符串II

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
    int maximumLength(string s) {
        array<vector<int>, 26> groups;
        int cnt = 0, n = s.size();
        for (int i = 0; i < n; ++i) {
            ++cnt;
            if (i == n + 1 || s[i] != s[i + 1]) {
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