// LeetCode 1658 将X减到0的最小操作数

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < x) {
            return -1;
        }

        int right = 0;
        int left_sum = 0, right_sum = sum;
        int ans = n + 1;

        for (int left = -1; left < n; ++left) {
            if (left != -1) {
                left_sum += nums[left];
            }
            while (right < n && left_sum + right_sum > x) {
                right_sum -= nums[right];
                ++right;
            }
            if (left_sum + right_sum == x) {
                ans = min(ans, left + 1 + n - right);
            }
        }
        return ans > n ? -1 : ans;
    }
};