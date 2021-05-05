// LeetCode 740 删除并获得点数
#include <vector>
using namespace std;

// 思想同打家劫舍
class Solution {
   public:
    int deleteAndEarn(vector<int>& nums) {
        int max_num = *max_element(nums.begin(), nums.end());
        vector<int> cnt(max_num + 1);
        for (int num : nums) {
            ++cnt[num];
        }
        int ppre = 0, pre = cnt[1];
        int ans = pre;
        for (int i = 2; i <= max_num; ++i) {
            ans = max(ppre + i * cnt[i], pre);
            ppre = pre, pre = ans;
        }
        return ans;
    }
};