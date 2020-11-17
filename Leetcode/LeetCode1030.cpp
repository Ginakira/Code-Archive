// LeetCode 1030 距离顺序排列矩阵单元格
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> ans;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                ans.emplace_back(vector<int>{i, j});
            }
        }
        sort(ans.begin(), ans.end(), [&](auto &a, auto &b) {
            return abs(a[0] - r0) + abs(a[1] - c0) <
                   abs(b[0] - r0) + abs(b[1] - c0);
        });
        return ans;
    }
};