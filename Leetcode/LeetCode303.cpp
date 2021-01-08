// LeetCode 303 区域和检索-数组不可变
#include <vector>
using namespace std;

// 前缀和
class NumArray {
   private:
    vector<int> prefixSum{0};

   public:
    NumArray(vector<int>& nums) {
        int sum = 0;
        for (int& num : nums) {
            sum += num;
            prefixSum.emplace_back(sum);
        }
    }

    int sumRange(int i, int j) { return prefixSum[j + 1] - prefixSum[i]; }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */