// LeetCode 不同路径 II

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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<int>> paths(n, vector<int>(m, 0));
        paths[0][0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    paths[i][j] = 0;
                    continue;
                }
                if (i - 1 >= 0) {
                    paths[i][j] += paths[i - 1][j];
                }
                if (j - 1 >= 0) {
                    paths[i][j] += paths[i][j - 1];
                }
            }
        }
        return paths[n - 1][m - 1];
    }
};