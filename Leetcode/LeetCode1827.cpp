// LeetCOde 1827 最少操作使数组递增

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int minOperations(vector<int>& nums) {
        size_t n = nums.size();
        int ops = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                continue;
            }
            ops += nums[i - 1] - nums[i] + 1;
            nums[i] = nums[i - 1] + 1;
        }
        return ops;
    }
};