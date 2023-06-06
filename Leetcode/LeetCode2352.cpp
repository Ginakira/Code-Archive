// LeetCode 2352 相等行列对

#include <algorithm>
#include <array>
#include <map>
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
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        map<vector<int>, int> row_mp;
        for (auto& row : grid) {
            ++row_mp[row];
        }

        int ans = 0;
        for (int j = 0; j < m; ++j) {
            vector<int> col(n);
            for (int i = 0; i < n; ++i) {
                col[i] = grid[i][j];
            }
            if (row_mp.count(col)) {
                ans += row_mp[col];
            }
        }
        return ans;
    }
};