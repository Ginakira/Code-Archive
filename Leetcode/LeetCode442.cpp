// LeetCode 442 数组中重复的数据

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> results;
        size_t n = nums.size();
        for (int i = 0; i < n; ++i) {
            int x = abs(nums[i]);
            if (nums[x - 1] > 0) {
                nums[x - 1] = -nums[x - 1];
            } else {
                results.push_back(x);
            }
        }
        return results;
    }
};