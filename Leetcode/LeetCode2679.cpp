// LeetCode 2679 矩阵中的和

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
    int matrixSum(vector<vector<int>>& nums) {
        int ans = 0;
        int n = nums.size(), m = nums[0].size();
        for (auto& num : nums) {
            sort(num.begin(), num.end(), std::greater());
        }
        for (int j = 0; j < m; ++j) {
            int max_elem = 0;
            for (int i = 0; i < n; ++i) {
                max_elem = max(max_elem, nums[i][j]);
            }
            ans += max_elem;
        }
        return ans;
    }
};