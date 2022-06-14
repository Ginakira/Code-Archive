// LeetCode 498 对角线遍历

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        size_t n = mat.size(), m = mat[0].size();
        vector<int> results;
        for (size_t i = 0; i < n + m - 1; ++i) {
            if (i & 1) {
                int x = i < m ? 0 : i - m + 1;
                int y = i < m ? i : m - 1;
                while (x < n && y >= 0) {
                    results.emplace_back(mat[x][y]);
                    ++x;
                    --y;
                }
            } else {
                int x = i < n ? i : n - 1;
                int y = i < n ? 0 : i - n + 1;
                while (x >= 0 && y < m) {
                    results.emplace_back(mat[x][y]);
                    --x;
                    ++y;
                }
            }
        }
        return results;
    }
};
