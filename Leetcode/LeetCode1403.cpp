// LeetCode 1403 非递增顺序的最小子序列

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> minSubsequence(vector<int>& nums) {
        vector<int> ans;
        int sum = accumulate(nums.begin(), nums.end(), 0), half = sum >> 1;
        int n = nums.size(), cur_sum = 0;
        sort(nums.begin(), nums.end(), greater<int>());
        for (int i = 0; i < n; ++i) {
            if (cur_sum > half) {
                break;
            }
            cur_sum += nums[i];
            ans.emplace_back(nums[i]);
        }
        return ans;
    }
};