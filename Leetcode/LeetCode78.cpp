// LeetCode 78 子集
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   private:
    vector<vector<int>> result;
    vector<int> current;

   public:
    void backtrace(vector<int>& nums, int cur) {
        if (cur == nums.size()) {
            result.emplace_back(current);
            return;
        }
        current.emplace_back(nums[cur]);
        backtrace(nums, cur + 1);
        current.pop_back();
        backtrace(nums, cur + 1);
        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        backtrace(nums, 0);
        return result;
    }
};