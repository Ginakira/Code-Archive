// LeetCode 724 寻找数组的中心索引
#include <numeric>
#include <vector>
using namespace std;

// 前缀和
// P[i]为原数组i位置上左侧所有元素的和
// 则成立条件为P[i] = P[n] - P[i] - nums[i];
// 可转化为2 * P[i] - nums[i] = P[n];
// P[n]为数组累加和
class Solution {
   public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if (2 * sum + nums[i] == total) {
                return i;
            }
            sum += nums[i];
        }
        return -1;
    }
};