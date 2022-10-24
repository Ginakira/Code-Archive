// LeetCode 915 分割数组

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int partitionDisjoint(vector<int>& nums) {
        size_t n = nums.size();
        vector<int> right_min(n);
        right_min[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            right_min[i] = min(right_min[i + 1], nums[i]);
        }
        for (int i = 0, max_num = 0; i < n - 1; ++i) {
            max_num = max(max_num, nums[i]);
            if (max_num <= right_min[i + 1]) {
                return i + 1;
            }
        }
        return -1;
    }
};