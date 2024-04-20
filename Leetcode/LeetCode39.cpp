// LeetCode 39 组合总和
#include <vector>
using namespace std;

// DFS 回溯 + 剪枝
class Solution {
   private:
    void helper(vector<int> &candidates, int target, int index,
                vector<int> &path, vector<vector<int>> &ans) {
        if (target == 0) {
            ans.emplace_back(path);
            return;
        } else if (target < 0) {
            return;
        }
        for (int i = index; i < candidates.size(); ++i) {
            if (target < candidates[i]) return;
            path.emplace_back(candidates[i]);
            helper(candidates, target - candidates[i], i, path, ans);
            path.pop_back();
        }
        return;
    }

   public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        vector<vector<int>> ans;
        helper(candidates, target, 0, path, ans);
        return ans;
    }
};