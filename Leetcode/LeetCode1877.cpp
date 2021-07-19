// LeetCode 1877 数组中最大数对和的最小值
#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 排序 + 双指针
class Solution {
   public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), left = 0, right = n - 1;
        int max_val = 0;
        while (left < right) {
            max_val = max(max_val, nums[left] + nums[right]);
            ++left, --right;
        }
        return max_val;
    }
};