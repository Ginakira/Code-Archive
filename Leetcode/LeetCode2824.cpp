// LeetCode 2824 统计和小于目标的下标对数目

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
    int countPairs(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        size_t n = nums.size();
        int ans = 0;
        for (size_t i = 0; i < n; ++i) {
            int up_bound = target - nums[i];
            auto it = lower_bound(nums.begin(), nums.begin() + i, up_bound);
            ans += distance(nums.begin(), it);
        }
        return ans;
    }
};
