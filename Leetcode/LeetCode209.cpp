// LeetCode 209 长度最小的子数组

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0, sum = 0;
        int min_len = INT_MAX;
        while (r < n) {
            sum += nums[r];
            ++r;
            if (sum < target) continue;
            while (sum >= target) {
                sum -= nums[l];
                ++l;
            }
            min_len = min(min_len, r - l + 1);
        }
        return min_len == INT_MAX ? 0 : min_len;
    }
};