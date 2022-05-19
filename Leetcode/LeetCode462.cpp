// LeetCode 462 最少移动次数使数组元素相等 II

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int minMoves2(vector<int>& nums) {
        size_t n = nums.size();
        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
        int target = nums[n / 2], ans = 0;
        for (int num : nums) {
            ans += abs(target - num);
        }
        return ans;
    }
};