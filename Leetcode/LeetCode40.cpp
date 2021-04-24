// LeetCode 40 组合总和II
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
   private:
    void helper(vector<int> &candidates, int index, int target,
                vector<int> &path, vector<vector<int>> &ans) {
        if (target == 0) {
            ans.emplace_back(path);
            return;
        }
        for (int i = index; i < candidates.size() && candidates[i] <= target;
             ++i) {
            if (i > index && candidates[i] == candidates[i - 1]) continue;
            path.emplace_back(candidates[i]);
            helper(candidates, i + 1, target - candidates[i], path, ans);
            path.pop_back();
        }
        return;
    }

   public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        vector<vector<int>> ans;
        helper(candidates, 0, target, path, ans);
        return ans;
    }
};