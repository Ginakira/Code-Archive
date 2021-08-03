// LeetCode 581 最短无序连续子数组

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 排序
class Solution {
   public:
    int findUnsortedSubarray(vector<int>& nums) {
        if (is_sorted(nums.begin(), nums.end())) {
            return 0;
        }

        vector<int> sorted_nums(nums);
        sort(sorted_nums.begin(), sorted_nums.end());

        int left = 0, right = nums.size() - 1;
        while (nums[left] == sorted_nums[left]) {
            ++left;
        }
        while (nums[right] == sorted_nums[right]) {
            --right;
        }
        return right - left + 1;
    }
};

// 一次遍历
class Solution2 {
   public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int max_n = INT_MIN, right = -1;
        int min_n = INT_MAX, left = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] >= max_n) {
                max_n = nums[i];
            } else {
                right = i;
            }
            if (nums[n - i - 1] <= min_n) {
                min_n = nums[n - i - 1];
            } else {
                left = n - i - 1;
            }
        }
        return right == -1 ? 0 : right - left + 1;
    }
};