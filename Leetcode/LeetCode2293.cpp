// LeetCode 2293 极大极小游戏

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int minMaxGame(vector<int>& nums) {
        size_t n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        vector<int> result(n / 2);
        for (size_t i = 0; i < n / 2; ++i) {
            if (i & 1) {
                result[i] = max(nums[i * 2], nums[i * 2 + 1]);
            } else {
                result[i] = min(nums[i * 2], nums[i * 2 + 1]);
            }
        }
        return minMaxGame(result);
    }
};