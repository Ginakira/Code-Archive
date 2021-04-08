// LeetCode 寻找旋转排序数组中的最小值II
#include <vector>
using namespace std;

class Solution {
   public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1, mid;
        while (left < right) {
            mid = (left + right) >> 1;
            if (nums[mid] < nums[right]) {
                right = mid;
            } else if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                // 如果nums[mid]和nums[right]相等，则可以忽略nums[right]，右边界收缩一位
                // 因为哪怕nums[right]就是答案，也有nums[mid]“作为备用”留在搜索区域内
                --right;
            }
        }
        return nums[left];
    }
};