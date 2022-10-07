// LeetCode 1800 最大升序子数组和

#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = 0, sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] <= nums[i - 1]) {
                sum = nums[i];
                continue;
            }
            sum += nums[i];
            ans = max(ans, sum);
        }
        return ans;
    }
};