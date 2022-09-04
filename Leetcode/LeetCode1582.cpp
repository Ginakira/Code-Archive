// LeetCode 1582 二进制矩阵中的特殊位置

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> row_cnt(n), col_cnt(m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 1) {
                    ++row_cnt[i];
                    ++col_cnt[j];
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 1 && row_cnt[i] == 1 && col_cnt[j] == 1) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};