#include <iostream>
#include <vector>
using namespace std;

// Solution 1 整体反转，再分别旋转两个部分
// 1 2 3 4 5 6 7, k = 3
// Step 1: 7 6 5 4 3 2 1
// Step 2: 5 6 7 4 3 2 1
// Step 3: 5 6 7 1 2 3 4
class Solution {
   public:
    void reverse(vector<int>& nums, int start, int end) {
        int n = (end - start) >> 1;
        for (int i = 0; i < n; ++i) {
            swap(nums[start + i], nums[end - i - 1]);
        }
        return;
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        reverse(nums, 0, n);
        reverse(nums, 0, k);
        reverse(nums, k, n);
        return;
    }
};