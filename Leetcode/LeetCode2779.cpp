// LeetCode 2779 数组的最大美丽值

#include <algorithm>
#include <array>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    int maximumBeauty(vector<int>& nums, int k) {
        ranges::sort(nums);
        int ans = 0;
        for (int l = 0, r = 0; r < nums.size(); ++r) {
            if (nums[r] - nums[l] <= 2 * k) {
                ans = max(ans, r - l + 1);
            } else {
                ++l;
            }
        }
        return ans;
    }
};