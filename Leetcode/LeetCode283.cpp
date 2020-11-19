// LeetCode 283 移动零
#include <vector>
using namespace std;

// 左指针指向已处理好的尾部
class Solution {
   public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), left = 0, right = 0;
        while (right < n) {
            if (nums[right]) {
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
        return;
    }
};

class Solution2 {
   public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0;
        while (right < n) {
            if (nums[right]) {
                nums[left++] = nums[right];
            }
            right++;
        }
        while (left < n) {
            nums[left++] = 0;
        }
        return;
    }
};
