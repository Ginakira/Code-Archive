// LeetCode 910 最小差值II

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
    int smallestRangeII(vector<int>& nums, int k) {
        ranges::sort(nums);
        int n = nums.size();
        int ans = nums[n - 1] - nums[0];
        int back_k = nums.back() - k, first_k = nums[0] + k;
        for (int i = 1; i < n; ++i) {
            ans = min(ans,
                      max(nums[i - 1] + k, back_k) - min(nums[i] - k, first_k));
        }
        return ans;
    }
};