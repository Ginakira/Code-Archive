// LeetCode 977 有序数组的平方

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 常规方法 nlogn
class Solution {
   public:
    vector<int> sortedSquares(vector<int>& nums) {
        for (auto& num : nums) {
            num *= num;
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};

// 双指针 On
class Solution2 {
   public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int left = 0, right = nums.size() - 1, ind = n - 1;
        while (left <= right) {
            if (abs(nums[left]) > abs(nums[right])) {
                result[ind] = nums[left] * nums[left];
                ++left;
            } else {
                result[ind] = nums[right] * nums[right];
                --right;
            }
            --ind;
        }
        return result;
    }
};