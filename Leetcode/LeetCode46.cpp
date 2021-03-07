// LeetCode 46 全排列
#include <vector>
using namespace std;

// 回溯法
class Solution {
   public:
    vector<vector<int>> permute(vector<int> &nums) {
        int n = nums.size();
        vector<vector<int>> ret;
        if (n == 0) return ret;
        vector<int> current;
        vector<bool> used(n, false);
        dfs(nums, 0, n, current, used, ret);
        return ret;
    }

    void dfs(vector<int> &nums, int depth, int len, vector<int> &current,
             vector<bool> &used, vector<vector<int>> &ret) {
        if (len == depth) {
            ret.push_back(current);
            return;
        }
        for (int i = 0; i < len; ++i) {
            if (used[i]) continue;
            used[i] = true;
            current.push_back(nums[i]);
            dfs(nums, depth + 1, len, current, used, ret);
            current.pop_back();
            used[i] = false;
        }
        return;
    }
};