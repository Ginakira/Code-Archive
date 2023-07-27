// LeetCode 2500 删除每行中的最大值

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
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        for (auto& g : grid) {
            sort(g.begin(), g.end(), greater<int>());
        }
        for (int j = 0; j < m; ++j) {
            int max_num = 0;
            for (int i = 0; i < n; ++i) {
                max_num = max(max_num, grid[i][j]);
            }
            ans += max_num;
        }
        return ans;
    }
};