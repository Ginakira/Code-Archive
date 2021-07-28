// LeetCode 598 范围求和II

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 暴力 超时
class Solution {
   public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        vector<vector<int>> matrix(m, vector<int>(n, 0));

        for (auto& op : ops) {
            int a = op[0], b = op[1];
            for (int i = 0; i < a; ++i) {
                for (int j = 0; j < b; ++j) {
                    ++matrix[i][j];
                }
            }
        }

        int max_val = 0, max_cnt = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] > max_val) {
                    max_val = matrix[i][j];
                    max_cnt = 1;
                } else if (matrix[i][j] == max_val) {
                    ++max_cnt;
                }
            }
        }
        return max_cnt;
    }
};

// 统计最终交集
class Solution2 {
   public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int min_m = m, min_n = n;
        for (auto& op : ops) {
            min_m = min(min_m, op[0]);
            min_n = min(min_n, op[1]);
        }
        return min_m * min_n;
    }
};