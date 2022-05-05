// LeetCode 713 乘积小于 K 的子数组

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int cnt = 0;
        int cur_product = 1;
        size_t n = nums.size();
        for (size_t l = 0, r = 0; r < n; ++r) {
            cur_product *= nums[r];
            while (l <= r && cur_product >= k) {
                cur_product /= nums[l];
                ++l;
            }
            cnt += r - l + 1;
        }
        return cnt;
    }
};