// LeetCode 363 矩形区域不超过K的最大数值和
#include <climits>
#include <set>
#include <vector>
using namespace std;

// 二分 + 集合
// 通常做法是我们枚举上下左右边界，但这样会造成过多的重复计算
// 所以我们只枚举矩形的上下边界，并计算出该边界内每列的元素和
// 则原问题转换成了如下一维问题：
// 给定一个整数数组和一个整数 k，计算该数组的最大区间和，要求区间和不超过 k
// 这样我们在枚举上下边界的时候，可以维护每列的元素和col_sum
// 我们要做的是在col_sum上寻找一个满足要求（小于等于k）的最大的区间和
// 此时可以使用前缀和来进行查找Sr-Sl的满足要求的最大值
// 但因为元素中可能含有负值，前缀和不一定是递增的，所以我们需要枚举右边界Sr，再去已经处理过的前缀和中满足要求的最小的Sl（因为要保证Sr-Sl尽可能地大）
// 要求为Sr-Sl<=k，可化为Sl>=Sr-k，所以要找第一个值大于或等于Sr-k的Sl，保证Sr-Sl尽可能大
class Solution {
   public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int ans = INT_MIN;
        int n = matrix.size(), m = matrix[0].size();
        for (int i = 0; i < n; ++i) {  // 枚举上边界
            vector<int> col_sum(m);
            for (int j = i; j < n; ++j) {      // 枚举下边界
                for (int k = 0; k < m; ++k) {  // 更新每列元素和
                    col_sum[k] += matrix[j][k];
                }
                int pre_sum = 0;
                set<int> pre_sum_set{0};
                for (int& num : col_sum) {
                    pre_sum += num;
                    auto sl = pre_sum_set.lower_bound(pre_sum - k);
                    if (sl != pre_sum_set.end()) {
                        ans = max(ans, pre_sum - *sl);
                    }
                    pre_sum_set.insert(pre_sum);
                }
            }
        }
        return ans;
    }
};

// 二维前缀和预处理 388ms 使用vector 1500ms
class Solution2 {
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