// LeetCode 413 等差数列划分

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return 0;
        }

        int d = nums[0] - nums[1], count = 0;
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            if (nums[i - 1] - nums[i] == d) {
                ++count;
            } else {
                count = 0;
                d = nums[i - 1] - nums[i];
            }
            ans += count;
        }
        return ans;
    }
};