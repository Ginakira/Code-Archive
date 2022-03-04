// LeetCode 2104 子数组范围和

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    long long subArrayRanges(vector<int>& nums) {
        long long sum = 0;
        size_t n = nums.size();
        for (size_t i = 0; i < n; ++i) {
            int min_num = nums[i], max_num = nums[i];
            for (size_t j = i + 1; j < n; ++j) {
                min_num = min(min_num, nums[j]);
                max_num = max(max_num, nums[j]);
                sum += max_num - min_num;
            }
        }
        return sum;
    }
};