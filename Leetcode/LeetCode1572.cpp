// LeetCode 1572 矩阵对角线元素的和

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
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        int n = mat.size(), m = mat[0].size();
        for (int i = 0, j = 0; i < n && j < m; ++i, ++j) {
            sum += mat[i][j];
            if (n - i - 1 == j) {
                continue;
            }
            sum += mat[n - i - 1][j];
        }
        return sum;
    }
};