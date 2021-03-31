// LeetCode 90 子集II
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
   private:
    vector<vector<int>> results;
    vector<int> temp;

    void backtrace(bool choose_pre, vector<int>& nums, int cur) {
        if (cur == nums.size()) {
            results.emplace_back(temp);
            return;
        }
        backtrace(false, nums, cur + 1);
        if (!choose_pre && cur > 0 && nums[cur - 1] == nums[cur]) {
            return;
        }
        temp.emplace_back(nums[cur]);
        backtrace(true, nums, cur + 1);
        temp.pop_back();
        return;
    }

   public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrace(false, nums, 0);
        return results;
    }
};