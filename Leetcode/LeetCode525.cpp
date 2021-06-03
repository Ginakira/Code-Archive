// LeetCode 525 连续数组
#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 问题可等价于1和0数量相同，如果把0视为-1，则为寻找和为0的最长子数组
class Solution {
   public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size(), pre_sum = 0;
        unordered_map<int, int> mp;
        int max_len = 0;
        mp[0] = -1;
        for (int i = 0; i < n; ++i) {
            pre_sum += (nums[i] == 1 ? 1 : -1);
            if (mp.find(pre_sum) != mp.end()) {
                max_len = max(max_len, i - mp[pre_sum]);
            } else {
                mp[pre_sum] = i;
            }
        }
        return max_len;
    }
};