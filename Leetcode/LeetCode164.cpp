// LeetCode 164 最大间距
#include <algorithm>
#include <vector>
using namespace std;

// 解法1：不讲武德sort一把梭 16ms
class Solution1 {
   public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0, n = nums.size();
        for (int i = 1; i < n; ++i) {
            int diff = abs(nums[i - 1] - nums[i]);
            ans = ans < diff ? diff : ans;
        }
        return ans;
    }
};