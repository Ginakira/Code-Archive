// LeetCode 363 矩形区域不超过K的最大数值和
#include <climits>
#include <vector>
using namespace std;

// 二维前缀和预处理 388ms
class Solution {
   public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int sum[110][110];
        int n = matrix.size(), m = matrix[0].size();
        // 二维前缀和预处理（下标映射为从1开始）
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] +
                            matrix[i - 1][j - 1];
            }
        }
        // 枚举左上角和右下角
        int ans = INT_MIN;
        for (int x1 = 1; x1 <= n; ++x1) {
            for (int y1 = 1; y1 <= m; ++y1) {
                for (int x2 = x1; x2 <= n; ++x2) {
                    for (int y2 = y1; y2 <= m; ++y2) {
                        int val = sum[x2][y2] - sum[x1 - 1][y2] -
                                  sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
                        if (val <= k) {
                            ans = max(ans, val);
                        }
                    }
                }
            }
        }
        return ans;
    }
};

// 暴力搜索 23/27 超时
class Solution3 {
   private:
    int ans = INT_MIN;
    int rows, cols, _k;

   public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        rows = matrix.size(), cols = matrix[0].size();
        _k = k;
        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                search(i, j, matrix);
            }
        }
        return ans;
    }

    void search(int row, int col, vector<vector<int>>& matrix) {
        for (int start_i = 0; start_i < rows; ++start_i) {
            for (int start_j = 0; start_j < cols; ++start_j) {
                // calc value start point is start_i, start_j
                if (start_i + row > rows || start_j + col > cols) continue;
                int val = 0;
                for (int i = start_i; i < start_i + row; ++i) {
                    for (int j = start_j; j < start_j + col; ++j) {
                        val += matrix[i][j];
                    }
                }
                if (val <= _k) {
                    ans = max(ans, val);
                }
            }
        }
        return;
    }
};