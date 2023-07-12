// LeetCode 931 下降路径最小和

#include <algorithm>
#include <array>
#include <limits>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// 递推
class Solution {
   public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        constexpr int INF = std::numeric_limits<int>::max();

        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int up_left = j > 0 ? matrix[i - 1][j - 1] : INF;
                int up = matrix[i - 1][j];
                int up_right = j < m - 1 ? matrix[i - 1][j + 1] : INF;
                matrix[i][j] += min({up_left, up, up_right});
            }
        }

        return *std::min_element(matrix[n - 1].begin(), matrix[n - 1].end());
    }
};

// dfs爆搜 TLE
class Solution_DFS_TLE {
   private:
    int ans = std::numeric_limits<int>::max();

    void dfs(const vector<vector<int>>& matrix, int n, int m, int x, int y,
             int cur_sum) {
        if (x < 0 || x >= n || y < 0 || y >= m) {
            if (x == n) {
                ans = min(ans, cur_sum);
            }
            return;
        }
        cur_sum += matrix[x][y];
        dfs(matrix, n, m, x + 1, y - 1, cur_sum);
        dfs(matrix, n, m, x + 1, y, cur_sum);
        dfs(matrix, n, m, x + 1, y + 1, cur_sum);
    }

   public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        for (int j = 0; j < m; ++j) {
            dfs(matrix, n, m, 0, j, 0);
        }
        return ans;
    }
};