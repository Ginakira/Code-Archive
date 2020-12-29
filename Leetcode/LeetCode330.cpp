// LeetCode 330 按要求补齐数组
#include <vector>
using namespace std;

// Solution1: 贪心
// maxi代表当前能表示的最大数+1（不能表示的最小数）
// https://pic.leetcode-cn.com/1609227757-DzEpBW-image.png
class Solution {
   public:
    int minPatches(vector<int>& nums, int n) {
        long long maxi = 1, res = 0, i = 0, len = nums.size();
        while (maxi <= n) {
            if (i < len && nums[i] <= maxi) {
                maxi += nums[i++];
            } else {
                maxi += maxi, ++res;
            }
        }
        return res;
    }
};
