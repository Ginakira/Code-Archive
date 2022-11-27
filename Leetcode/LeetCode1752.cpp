// LeetCode 1752 检查数组是否经排序和轮转得到

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    bool check(vector<int>& nums) {
        int inversion_cnt = 0;
        size_t n = nums.size();
        for (size_t i = 0; i < n; ++i) {
            int next_num = (i == n - 1) ? nums[0] : nums[i + 1];
            inversion_cnt += (nums[i] > next_num);
            if (inversion_cnt > 1) {
                return false;
            }
        }
        return inversion_cnt <= 1;
    }
};