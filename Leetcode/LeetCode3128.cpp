// LeetCode 3128 直角三角形

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
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> col_cnt(m, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                col_cnt[j] += grid[i][j];
            }
        }
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            int row_cnt = accumulate(grid[i].begin(), grid[i].end(), 0);
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    ans += (row_cnt - 1) * (col_cnt[j] - 1);
                }
            }
        }
        return ans;
    }
};