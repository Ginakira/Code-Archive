// LeetCode 795 区间子数组个数

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int ans = 0;
        int last_ava = -1, last_too_high = -1;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] >= left && nums[i] <= right) {
                last_ava = i;
            } else if (nums[i] > right) {
                last_too_high = i;
                last_ava = -1;
            }
            if (last_ava != -1) {
                ans += last_ava - last_too_high;
            }
        }
        return ans;
    }
};