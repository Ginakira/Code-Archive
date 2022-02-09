// LeetCode2006 差的绝对值为K的数对数目

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int countKDifference(vector<int>& nums, int k) {
        int ans = 0;
        size_t n = nums.size();
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = i + 1; j < n; ++j) {
                if (abs(nums[i] - nums[j]) == k) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};