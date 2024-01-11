// LeetCode 2397 被列覆盖的最多行数

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
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> status(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j]) {
                    status[i] |= (1 << j);
                }
            }
        }

        int ans = 0;
        int mask = 0;
        int limit = (1 << m);
        while (++mask < limit) {
            if (__builtin_popcount(mask) != numSelect) {
                continue;
            }
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (status[i] == (status[i] & mask)) {
                    ++cnt;
                }
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};