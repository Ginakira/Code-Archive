// LeetCode 216 组合总和II
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
   private:
    const int START = 1, END = 9;

    void helper(int start, int n, int target, vector<int> &path,
                vector<vector<int>> &ans) {
        if (path.size() == n) {
            if (target == 0) ans.emplace_back(path);
            return;
        }
        for (int i = start; i <= END; ++i) {
            if (i > target) break;
            path.emplace_back(i);
            helper(i + 1, n, target - i, path, ans);
            path.pop_back();
        }
        return;
    }

   public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path;
        vector<vector<int>> ans;
        helper(START, k, n, path, ans);
        return ans;
    }
};