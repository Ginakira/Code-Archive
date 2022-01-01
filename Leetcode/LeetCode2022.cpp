// LeetCode 2022 将一维数组转变成二维数组

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> construct2DArray(vector<int>& original, int n, int m) {
        int len = original.size();
        if (len != n * m) {
            return {};
        }
        vector<vector<int>> ans(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans[i][j] = original[i * m + j];
            }
        }
        return ans;
    }
};