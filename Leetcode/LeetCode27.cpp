// LeetCode 27 移除元素
#include <vector>
using namespace std;

class Solution {
   public:
    int removeElement(vector<int>& nums, int val) {
        size_t n = nums.size();
        if (n == 0) return 0;

        int slow = 0, fast = 0;
        for (size_t i = 0; i < n; ++i) {
            if (nums[i] != val) {
                nums[slow++] = nums[fast];
            }
            ++fast;
        }
        return slow;
    }
};

// 优化后的双指针 优化掉了符合条件元素的复制操作
class Solution2 {
   public:
    int removeElement(vector<int>& nums, int val) {
        size_t n = nums.size();
        if (n == 0) return 0;

        int left = 0, right = n;
        while (left < right) {
            if (nums[left] == val) {
                nums[left] = nums[--right];
            } else {
                ++left;
            }
        }
        return left;
    }
};