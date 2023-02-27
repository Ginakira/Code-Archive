// LeetCode 1144 递减元素使数组呈锯齿状

#include <algorithm>
#include <limits>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   private:
    int helper(const vector<int>& nums, int start_pos) {
        int ops = 0;
        int n = nums.size();
        for (int i = start_pos; i < n; i += 2) {
            int min_neighbor = std::numeric_limits<int>::max();
            if (i - 1 >= 0) {
                min_neighbor = min(min_neighbor, nums[i - 1]);
            }
            if (i + 1 < n) {
                min_neighbor = min(min_neighbor, nums[i + 1]);
            }
            ops += max(nums[i] - min_neighbor + 1, 0);
        }
        return ops;
    }

   public:
    int movesToMakeZigzag(vector<int>& nums) {
        return min(helper(nums, 0), helper(nums, 1));
    }
};