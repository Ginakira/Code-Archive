// LeetCode 2639 查询网格图中每一列的宽度

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
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int m = grid[0].size();
        vector<int> ans(m);
        for (auto& g : grid) {
            for (int i = 0; i < m; ++i) {
                ans[i] = max(ans[i], static_cast<int>(to_string(g[i]).size()));
            }
        }
        return ans;
    }
};