// LeetCode 3238 求出胜利玩家的数目

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
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector<array<int, 11>> cnt(n);
        for (const auto& p : pick) {
            int x = p[0], y = p[1];
            ++cnt[x][y];
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (ranges::any_of(cnt[i], [i](int num) { return num > i; })) {
                ++ans;
            }
        }
        return ans;
    }
};