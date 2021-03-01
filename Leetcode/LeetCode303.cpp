// LeetCode 303 区域和检索-数组不可变
#include <vector>
using namespace std;

// 前缀和
class NumArray {
   public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        pre_sum.resize(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pre_sum[i + 1] = pre_sum[i] + nums[i];
        }
    }

    int sumRange(int i, int j) { return pre_sum[j + 1] - pre_sum[i]; }

   private:
    vector<int> pre_sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */