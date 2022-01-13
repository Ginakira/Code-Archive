// LeetCode 747 至少是其他数字两倍的最大数

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int dominantIndex(vector<int>& nums) {
        int max_index = max_element(nums.begin(), nums.end()) - nums.begin();
        int max_num = nums[max_index];
        for (int i = 0, n = nums.size(); i < n; ++i) {
            if (i == max_index) continue;
            if (nums[i] * 2 > max_num) {
                return -1;
            }
        }
        return max_index;
    }
};