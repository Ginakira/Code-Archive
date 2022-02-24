// LeetCOde 1706 球会落何处

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> ans(m);
        for (int j = 0; j < m; ++j) {
            int col = j;
            for (const auto& row : grid) {
                int dir = row[col];
                col += dir;
                if (col < 0 || col == m || row[col] != dir) {
                    col = -1;
                    break;
                }
            }
            ans[j] = col;
        }
        return ans;
    }
};