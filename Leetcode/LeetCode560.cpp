// LeetCode 560 和为K的子数组
#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int pre_sum = 0, ans = 0;
        unordered_map<int, int> count;
        for (int i = 0; i < n; ++i) {
            ++count[pre_sum];
            pre_sum += nums[i];
            if (count.find(pre_sum - k) != count.end()) {
                ans += count[pre_sum - k];
            }
        }
        return ans;
    }
};