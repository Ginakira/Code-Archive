// LeetCodee 561 数组拆分 I
#include <algorithm>
#include <vector>
using namespace std;

// 贪心 排序
class Solution {
   public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < nums.size(); i += 2) {
            ans += nums[i];
        }
        return ans;
    }
};