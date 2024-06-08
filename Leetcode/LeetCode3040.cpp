// LeetCode 3040 相同分数的最大操作数目 II

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
    int maxOperations(vector<int> &nums) {
        int n = nums.size();
        vector<vector<int>> mem(n, vector<int>(n));
        auto helper = [&](int i, int j, int target) {
            for (auto &row : mem) {
                ranges::fill(row, -1);
            }
            bool resolved = false;
            function<int(int, int)> dfs = [&](int i, int j) {
                if (resolved) {
                    return 0;
                }
                if (i >= j) {
                    resolved = true;
                    return 0;
                }
                int &res = mem[i][j];
                if (res != -1) {
                    return res;
                }
                res = 0;
                if (nums[i] + nums[i + 1] == target) {
                    res = max(res, dfs(i + 2, j) + 1);
                }
                if (nums[j - 1] + nums[j] == target) {
                    res = max(res, dfs(i, j - 2) + 1);
                }
                if (nums[i] + nums[j] == target) {
                    res = max(res, dfs(i + 1, j - 1) + 1);
                }
                return res;
            };
            return dfs(i, j);
        };
        int res1 = helper(2, n - 1, nums[0] + nums[1]);
        int res2 = helper(0, n - 3, nums[n - 2] + nums[n - 1]);
        int res3 = helper(1, n - 2, nums[0] + nums[n - 1]);
        return max({res1, res2, res3}) + 1;
    }
};