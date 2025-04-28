// LeetCode 2302 统计得分小于K的子数组数目

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
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0;
        int n = nums.size();
        long long cur_score = 0;
        for (int l = 0, r = 0; r < n; ++r) {
            cur_score += nums[r];
            while (l <= r && cur_score * (r - l + 1) >= k) {
                cur_score -= nums[l++];
            }
            ans += r - l + 1;
        }
        return ans;
    }
};