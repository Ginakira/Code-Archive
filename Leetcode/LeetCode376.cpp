// LeetCode 376 摆动序列
#include <vector>
using namespace std;

// Solution1 动态规划
// up代表末尾两个数字递增的选出的最长的序列
// down代表末尾两个数字递减的选出的最长的序列
class Solution {
   public:
    int wiggleMaxLength(vector<int>& nums) {
        int up = 1, down = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                up = down + 1;
            } else if (nums[i] < nums[i - 1]) {
                down = up + 1;
            }
        }
        return nums.size() == 0 ? 0 : max(up, down);
    }
};