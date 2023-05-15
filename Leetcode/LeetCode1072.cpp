// LeetCode 1072 按列翻转得到最大值等行数

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
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        unordered_map<string, int> mp;
        for (int i = 0; i < n; ++i) {
            string s = string(m, '0');
            for (int j = 0; j < m; ++j) {
                // If matrix[i][0] is zero, flip it.
                s[j] = '0' + (matrix[i][j] ^ matrix[i][0]);
            }
            ++mp[s];
        }
        int ans = 0;
        for (auto& [k, v] : mp) {
            ans = max(ans, v);
        }
        return ans;
    }
};