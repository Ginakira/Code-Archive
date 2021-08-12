// 剑指 Offer 57. 和为s的两个数字

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == target) {
                return {nums[left], nums[right]};
            } else if (sum < target) {
                ++left;
            } else {
                --right;
            }
        }
        return {-1, -1};
    }
};