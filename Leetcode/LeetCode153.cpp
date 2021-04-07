// LeetCode 153 寻找旋转排序数组中的最小值
#include <vector>
using namespace std;

class Solution {
   public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1, mid;
        while (left < right) {
            mid = (left + right) >> 1;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};