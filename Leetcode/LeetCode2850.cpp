// LeetCode 2850 将石头分散到网格图的最少移动次数

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
    int minimumMoves(vector<vector<int>> &grid) {
        constexpr int n = 3;
        constexpr int m = 3;
        vector<tuple<int, int>> more, less;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] > 1) {
                    for (int k = 2; k <= grid[i][j]; ++k) {
                        more.emplace_back(i, j);
                    }
                } else if (grid[i][j] == 0) {
                    less.emplace_back(i, j);
                }
            }
        }

        int ans = numeric_limits<int>::max();
        do {
            int steps = 0;
            for (int i = 0; i < more.size(); ++i) {
                auto &[more_i, more_j] = more[i];
                auto &[less_i, less_j] = less[i];
                steps += abs(more_i - less_i) + abs(more_j - less_j);
            }
            ans = min(ans, steps);
        } while (next_permutation(more.begin(), more.end()));

        return ans;
    }
};
