// LeetCode 918 环形子数组的最大和

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
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int pre_max = nums[0], max_res = nums[0];
        int pre_min = nums[0], min_res = nums[0];
        int sum = nums[0];
        for (int i = 1; i < n; ++i) {
            pre_max = max(pre_max + nums[i], nums[i]);
            max_res = max(max_res, pre_max);
            pre_min = min(pre_min + nums[i], nums[i]);
            min_res = min(min_res, pre_min);
            sum += nums[i];
        }
        if (max_res < 0) {
            return max_res;
        } else {
            return max(max_res, sum - min_res);
        }
    }
};