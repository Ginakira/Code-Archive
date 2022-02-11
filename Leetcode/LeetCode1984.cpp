// LeetCode 1984 学生分数的最小差值

#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    int minimumDifference(vector<int>& nums, int k) {
        if (k == 1) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int left = 0, right = k - 1, min_diff = INT_MAX;
        while (right < nums.size()) {
            min_diff = min(min_diff, nums[right] - nums[left]);
            ++left, ++right;
        }
        return min_diff;
    }
};