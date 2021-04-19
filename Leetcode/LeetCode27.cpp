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