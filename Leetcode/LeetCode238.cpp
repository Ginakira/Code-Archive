// LeetCode 238 除自身以外数组的乘积
#include <vector>
using namespace std;

// 结果等于左面数乘积 * 右面数乘积
class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 1), right(n, 1), ans(n);
        left[0] = 1;
        for (int i = 1; i < n; ++i) {
            left[i] = left[i - 1] * nums[i - 1];
        }
        right[n - 1] = 1;
        ans[n - 1] = left[n - 1] * right[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            right[i] = right[i + 1] * nums[i + 1];
            ans[i] = left[i] * right[i];
        }
        return ans;
    }
};

// 优化空间 使用结果数组代替left，最后倒序累乘
class Solution2 {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        ans[0] = 1;
        for (int i = 1; i < n; ++i) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }
        int R = 1;
        for (int i = n - 1; i >= 0; --i) {
            ans[i] *= R;
            R *= nums[i];
        }
        return ans;
    }
};