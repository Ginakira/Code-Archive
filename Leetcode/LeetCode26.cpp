#include <vector>
using namespace std;

// 26. 删除排序数组中的重复项

// 双指针法
class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (!n) return 0;
        int count = 1, pre = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] == pre) continue;
            nums[count++] = nums[i];
            pre = nums[i];
        }
        return count;
    }
};