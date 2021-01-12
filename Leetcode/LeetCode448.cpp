// LeetCode 448 找到所有数组中消失的数字
#include <cmath>
#include <vector>
using namespace std;

// 因为题目中要求不允许使用额外的空间且复杂度为On，所以不能使用哈希表
// 我们可以将每一个数字作为下标，将这个下标位置上的数变为负数
// 最后遍历一次，所有整数的位置对应的索引就是没有出现过的数字
class Solution {
   public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ret;
        for (int i = 0; i < nums.size(); ++i) {
            int ind = abs(nums[i]) - 1;
            nums[ind] = -abs(nums[ind]);
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) ret.push_back(i + 1);
        }
        return ret;
    }
};