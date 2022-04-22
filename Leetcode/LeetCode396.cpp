// LeetCode 396 旋转函数

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int maxRotateFunction(vector<int>& nums) {
        int total_sum = accumulate(nums.begin(), nums.end(), 0);
        size_t n = nums.size();
        int current_f = 0;
        for (size_t i = 0; i < n; ++i) {
            current_f += i * nums[i];
        }
        int max_ans = current_f;
        for (int i = n - 1; i > 0; --i) {
            current_f += total_sum - n * nums[i];
            max_ans = max(max_ans, current_f);
        }
        return max_ans;
    }
};
