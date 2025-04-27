// LeetCode 3392 统计符合条件长度为3的子数组数目

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
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            if (2 * (nums[i] + nums[i - 2]) == nums[i - 1]) {
                ++ans;
            }
        }
        return ans;
    }
};