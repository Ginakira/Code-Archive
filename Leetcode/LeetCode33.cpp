// LeetCode 33 搜索旋转排序数组
#include <vector>
using namespace std;

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;
        int left = 0, right = n - 1, mid;
        while (left <= right) {
            mid = (left + right) >> 1;
            if (nums[mid] == target) return mid;
            if (nums[left] <= nums[mid]) {  // 代表左半部分是有序的
                if (target >= nums[left] &&
                    target < nums[mid]) {  // 在左半部分内则收缩右侧边界
                    right = mid - 1;
                } else {  // 否则下次去右半部分寻找
                    left = mid + 1;
                }
            } else {  // 右半部分有序
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};