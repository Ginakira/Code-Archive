// LeetCode 2661 找出叠涂元素

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
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, pair<int, int>> num_to_ind;
        int n = mat.size(), m = mat[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                num_to_ind[mat[i][j]] = {i, j};
            }
        }
        vector<int> row_cnt(n, 0), col_cnt(m, 0);
        for (int k = 0; k < arr.size(); ++k) {
            auto [i, j] = num_to_ind[arr[k]];
            ++row_cnt[i];
            ++col_cnt[j];
            if (row_cnt[i] == m || col_cnt[j] == n) {
                return k;
            }
        }
        return -1;
    }
};