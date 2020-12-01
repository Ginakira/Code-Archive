// LeetCode 34 在排序数组中查找元素的第一个和最后一个位置

#include <vector>
using namespace std;

// 解法1: 两次二分 （二分变形的0001111和11110000问题）
class Solution {
   public:
    int findFirstIndex(vector<int> &nums, int target) {
        if (nums.size() == 0) return -1;
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[left] == target ? left : -1;
    }

    int findLastIndex(vector<int> &nums, int target) {
        if (nums.size() == 0) return -1;
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right + 1) >> 1;
            if (nums[mid] <= target) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return nums[left] == target ? left : -1;
    }

    vector<int> searchRange(vector<int> &nums, int target) {
        int first_index = findFirstIndex(nums, target);
        int last_index = findLastIndex(nums, target);
        return vector<int>{first_index, last_index};
    }
};