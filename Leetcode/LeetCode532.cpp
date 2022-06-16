// LeetCode 532 数组中的 k-diff 数对

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

// 暴力
class Solution {
   public:
    int findPairs(vector<int>& nums, int k) {
        unordered_set<int> seen;
        unordered_set<int> result;
        for (auto& num : nums) {
            if (seen.count(num - k)) {
                result.emplace(num - k);
            }
            if (seen.count(num + k)) {
                result.emplace(num);
            }
            seen.emplace(num);
        }
        return result.size();
    }
};

// 双指针
class Solution2 {
   public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        size_t left = 0, right = 0, n = nums.size();
        int result = 0;
        for (left = 0; left < n; ++left) {
            if (left != 0 && nums[left] == nums[left - 1]) {
                continue;
            }
            while (right < n &&
                   (nums[right] < nums[left] + k || right <= left)) {
                ++right;
            }
            if (right < n && nums[left] + k == nums[right]) {
                ++result;
            }
        }
        return result;
    }
};
