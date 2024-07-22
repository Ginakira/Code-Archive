// LeetCode 2101 引爆最多的炸弹

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
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        auto in_range = [](int x, int y, int r, int nx, int ny) -> bool {
            return 1LL * (nx - x) * (nx - x) + 1LL * (ny - y) * (ny - y) <=
                   1LL * r * r;
        };
        vector<vector<int>> g(n);

        for (int i = 0; i < n; ++i) {
            int x = bombs[i][0], y = bombs[i][1], r = bombs[i][2];
            for (int j = 0; j < n; ++j) {
                int nx = bombs[j][0], ny = bombs[j][1];
                if (j == i) {
                    continue;
                }
                if (in_range(x, y, r, nx, ny)) {
                    g[i].emplace_back(j);
                }
            }
        }

        int ans = 0;
        function<int(int, vector<int>&)> helper = [&](int start,
                                                      vector<int>& denoted) {
            if (denoted[start]) {
                return 0;
            }
            int cnt = 1;
            denoted[start] = 1;
            for (int next : g[start]) {
                cnt += helper(next, denoted);
            }
            return cnt;
        };
        for (int i = 0; i < n; ++i) {
            vector<int> denoted(n, 0);
            ans = max(ans, helper(i, denoted));
        }
        return ans;
    }
};