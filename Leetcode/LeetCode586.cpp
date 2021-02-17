// LeetCode 566 重塑矩阵
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int rows = nums.size(), cols = nums[0].size();
        if (rows * cols != r * c) return nums;

        vector<vector<int>> ret(r, vector<int>(c, 0));
        for (int i = 0, n = rows * cols; i < n; ++i) {
            ret[i / c][i % c] = nums[i / cols][i % cols];
        }
        return ret;
    }
};