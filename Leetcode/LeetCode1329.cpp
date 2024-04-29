// LeetCode 1329 将矩阵按对角线排序

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
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> diagonal(n + m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                diagonal[i - j + m].emplace_back(mat[i][j]);
            }
        }
        for (auto& d : diagonal) {
            sort(d.rbegin(), d.rend());
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                mat[i][j] = diagonal[i - j + m].back();
                diagonal[i - j + m].pop_back();
            }
        }
        return mat;
    }
};