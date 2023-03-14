// LeetCode 1605 给定行和列的和求可行矩阵

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum,
                                      vector<int>& colSum) {
        int n = rowSum.size(), m = colSum.size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (rowSum[i] == 0 || colSum[j] == 0) {
                    continue;
                }
                ans[i][j] = min(rowSum[i], colSum[j]);
                rowSum[i] -= ans[i][j];
                colSum[j] -= ans[i][j];
            }
        }
        return ans;
    }
};